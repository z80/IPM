
require( "bit" )
require( "unclasslib" )

local HEADER = 0xE6
local ADDR   = 0xFF
local I2C_ADDR = 10
local I2C_TIMEOUT = 1.5
local I2C_CMD_BMSD = 5

function crc8( inData, seed )
    seed = seed or 0
    for bitsLeft=8, 1, -1 do
        local temp = bit.band( bit.bxor( seed, inData ), 0x01 )
    if ( temp == 0 ) then
        seed = bit.rshift( seed, 1 )
    else
        seed = bit.bxor( seed, 0x18 )
        seed = bit.rshift( seed, 1 )
        seed = bit.bor( seed, 0x80 )
    end
    inData = bit.rshift( inData, 1 )
    end
    return seed
end

function crcMsg( t )
    local seed = 0
    local cnt = #t
    for i = 2, cnt do
        seed = crc8( t[i], seed )
    end
    return seed
end

function mirrorBits( arg )
    local res = 0
    for i=0, 7 do
        local b = bit.lshift( 1, i )
        local val = ( bit.band( arg, b ) ~= 0 ) and 1 or 0
    local b = bit.lshift( val, 7-i )
    res = res + b
    end
    return res
end

function invertBits( arg )
    local res = bit.band( bit.bnot( arg ), 0xFF )
    return res
end

BMSD = class()

function BMSD:__init( mcu )
    self.mcu = mcu
end

function BMSD:i2cIo( cmd, arg, crc, mirror, invert )
    arg = arg or 0
    local t = { HEADER, ADDR, cmd, arg }
    local c = crc or crcMsg( t )
    display( unpack( t ) )
    print( "one" )
    t[5] = c
    display( unpack( t ) )
    local mcu = self.mcu
    mcu:i2cSetAddr( I2C_ADDR )
    print( "two" )
    if ( mirror ) then
        for i=1, #t do
            t[i] = mirrorBits( t[i] )
        end
    end
    if ( invert ) then
        for i=1, #t do
            t[i] = invertBits( t[i] )
        end        
    end
    mcu:i2cSetBuf( 0, I2C_CMD_BMSD, unpack( t ) )
    print( "three" )
    mcu:i2cIo( 6, 0 )
    print( "four" )
    while true do
        local res, val = mcu:i2cStatus()
        if ( res ) then
            if ( val == 0 ) then
                send( "print( \'I2C send sucess\' )" )
                return true
            end
        else
            return false
        end
        sleep( 0.1 )
    end
    print( "five" )
    send( "print( \'Error: I2C io error BMSD IO\' )" )
    print( "six" )
    return false
end

function BMSD:enumCrc( cmd, arg, mirror, invert )
    for i=0, 255 do
        local res = self:i2cIo( cmd or 0x51, arg or 0x00, i, mirror, invert )
        display( string.format( "$s, CRC = %h", tostring( res ), i ) )
        sleep( 1.1 )
    end
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
    sleep( 0.5 )
    res = self:i2cIo( 0xA3, speed )
    if ( not res ) then
        send( "print( \'Error: BMSD speed\' )" )
    end
    return res
end



