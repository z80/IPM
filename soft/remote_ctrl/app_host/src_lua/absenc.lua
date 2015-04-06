
require( "bit" )
require( "unclasslib" )

local I2C_ADDR = 10

local CMD_BITS        = 7
local CMD_DELAY       = 8
local CMD_DELAY_FRONT = 9
local CMD_DELAY_BACK = 10

Absenc = class()

function Absenc:__init( mcu )
  self.mcu = mcu
end

function Absenc:setBits( bits )
  bits = bits or 12
  local res = self:cmd_raw( CMD_BITS, bits, 0, 0 )
  return res
end

function Absenc:setDelay( delay )
  bits = bits or 12
  local res = self:cmd_raw( CMD_DELAY, delay, 0, 0 )
  return res
end

function Absenc:cmd_raw( cmd, ... )
    local mcu = self.mcu
    local t = {...}
    local cnt = #(t)
    mcu:i2cSetAddr( I2C_ADDR )
    mcu:i2cSetBuf( 0, cmd, unpack( t ) )
    mcu:i2cIo( cnt + 1, 0 )
    while true do
        local res, val = mcu:i2cStatus()
        if ( res ) then
            if ( val == 0 ) then
                send( "print( \'I2C send sucess\' )" )
                return true
            end
        else
            send( "print( \'I2C failure!!!\' )" )
            return false
        end
        sleep( 0.1 )
    end
    send( "print( \'Error: I2C io error!!!\' )" )
    return false
end
