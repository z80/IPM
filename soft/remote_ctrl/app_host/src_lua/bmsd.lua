
require( "bit" )
require( "unclasslib" )

local HEADER = 0xE6
local ADDR   = 0xFF
local I2C_ADDR = 10
local I2C_TIMEOUT = 1.5

function crc8( inData, seed )
    seed = seed or 0
    for bitsLeft=8, 1, -1 do
        local temp = bit.band( bit.bxor( seed, inData ), 0x01 )
	if ( temp == 0 ) then
	    seed = bit.rshift( seed, 1 )
	else
	    seed = bit.bxor( seed, 0x18 )
	    seed = bit.rshift( seed, 1 )
	    seed = bit.bor( 0x80 )
	end
	inData = bit.rshift( inData, 1 )
    end
    return seed
end

function crc( t )
    local seed = 0
    local cnt = #t
    for i = 1, cnt do
        seed = crc8( t[i], seed )
    end
    return seed
end

BMSD = class()

function BMSD:__init( mcu )
    self.mcu = mcu
end

function BMSD:i2cIo( cmd, arg )
    arg = arg or 0
    local t = { HEADER, ADDR, cmd, arg }
    local c = crc( t )
    t[5] = c
    local mcu = self.mcu
    mcu:i2cSetAddr( I2C_ADDR )
    mcu:i2cSetBuf( 0, unpack( t ) )
    mcu:i2cIo()
    while true do
        local res = ( mcu:i2cStatus() == 0 )
	if ( res ) then
            return true
	end
        sleep( 0.1 )
    end
    send( "print( \'Error: I2C io error BMSD IO\' )" )
    return false
end

function BMSD:start()
    local res = self:i2cIo( 0x51 )
    return res
end

-- Speed here is in percents from -100 to 100
function BMSD:move( speed )
    speed = speed or 10
    speed = ( speed <= 100 ) and speed or 100
    speed = ( speed >= -100 ) and speed or -100
    local dir = ( speed >= 0 ) and 1 or 0
    speed = speed * 250 / 100
    local res = self:i2cIo( 0xA7, dir )
    if ( not res ) then
        send( "print( \'Error: BMSD dir\' )" )
	return false
    end
    res = self:i2cIo( 0xA3, speed )
    if ( not res ) then
        send( "print( \'Error: BMSD speed\' )" )
    end
    return res
end



