
require( "bit" )
require( "unclasslib" )

local VOLT_ADDR = { 10, 12 }
local EN_ADDR   = { 11, 13 }
local CMD_VOLT1 = 1
local CMD_VOLT2 = 2

ESCON = class()

function ESCON:i2cIo( addr, ... )
    local mcu = self.mcu
    local res = mcu:i2cSetAddr( addr )
    if ( not res ) then
        display( "ESCON ERROR: failsed to sed I2C address = " .. tostring( addr ) )
	return false
    end
    res = mcu:i2cSetBuf( 0, ... )
    if ( not res ) then
        display( "ESCON ERROR: failsed to sed I2C buffer" )
	return false
    end
    local t = { ... }
    mcu:i2cIo( #t, 0 )
    while true do
        local res, val = mcu:i2cStatus()
	if ( res ) then
            if ( val == 0 ) then
                display( "ESCON: i2cIo succeded" )
		return true
	    end
	else
            return false
	end
	sleep( 0.1 )
    end
    return false
end

function ESCON:__init( mcu )
    self.mcu = mcu
    self.enBits = { 0, 0 }
end

function ESCON:init()
    local res
    for i=1, 4 do
        self:stop( i )
	self:setSpeed( i, 0 )
    end
end

function ESCON:stop( index )
    local addr, val
    if ( index == 1 ) then
        self.enBits[1] = bit.band( self.enBits[1], 0x02 )
	val = self.enBits[1]
        addr = EN_ADDR[1]
    elseif ( index == 2 ) then
        self.enBits[1] = bit.band( self.enBits[1], 0x01 )
	val = self.enBits[1]
	addr = EN_ADDR[1]
    elseif ( index == 3 ) then
        self.enBits[2] = bit.band( self.enBits[2], 0x02 )
	val = self.enBits[2]
        addr = EN_ADDR[2]
    elseif ( index ==4 ) then
        self.enBits[2] = bit.band( self.enBits[2], 0x01 )
	val = self.enBits[2]
        addr = EN_ADDR[2]
    end
    local res = self:i2cIo( addr, val )
    return res
end

function ESCON:start()
    local addr, val
    if ( index == 1 ) then
        self.enBits[1] = bit.bor( self.enBits[1], 0x01 )
	val = self.enBits[1]
        addr = EN_ADDR[1]
    elseif ( index == 2 ) then
        self.enBits[1] = bit.bor( self.enBits[1], 0x02 )
	val = self.enBits[1]
	addr = EN_ADDR[1]
    elseif ( index == 3 ) then
        self.enBits[2] = bit.bor( self.enBits[2], 0x01 )
	val = self.enBits[2]
        addr = EN_ADDR[2]
    elseif ( index == 4 ) then
        self.enBits[2] = bit.bor( self.enBits[2], 0x02 )
	val = self.enBits[2]
        addr = EN_ADDR[2]
    end
    local res = self:i2cIo( addr, val )
    return res
end

function ESCON:setSpeed( index, val )
    val = val or 0
    val = ( val <= 100 ) and val or 100
    val = ( val >= -100 ) and val or -100
    val = math.floor( (val / 200 + 0.5) * 255 + 0.5 )
    local addr = ( index < 3 ) and VOLT_ADDR[1] or VOLT_ADDR[2]
    local cmd
    if ( index == 1 ) then
        cmd = CMD_VOLT1
    elseif ( index == 2 ) then
        cmd = CMD_VOLT2
    elseif ( index == 3 ) then
        cmd = CMD_VOLT1
    elseif ( index == 4 ) then
        cmd = CMD_VOLT2
    end
    local res = self:i2cIo( addr, cmd, val )
    return res
end

function ESCON:move( index, val )
    self:setSpeed( index, val )
end




