
require( "unclasslib" )
local bit = require( "bitop" )

local LSM303DLH_DEVICE   = 0
local LSM303DLM_DEVICE   = 1
local LSM303DLHC_DEVICE  = 2
local LSM303_DEVICE_AUTO = 3

-- SA0_A states

local LSM303_SA0_A_LOW  = 0
local LSM303_SA0_A_HIGH = 1
local LSM303_SA0_A_AUTO = 2

-- register addresses

local LSM303_CTRL_REG1_A       = 0x20
local LSM303_CTRL_REG2_A       = 0x21
local LSM303_CTRL_REG3_A       = 0x22
local LSM303_CTRL_REG4_A       = 0x23
local LSM303_CTRL_REG5_A       = 0x24
local LSM303_CTRL_REG6_A       = 0x25 -- DLHC only
local LSM303_HP_FILTER_RESET_A = 0x25 -- DLH, DLM only
local LSM303_REFERENCE_A       = 0x26
local LSM303_STATUS_REG_A      = 0x27

local LSM303_OUT_X_L_A         = 0x28
local LSM303_OUT_X_H_A         = 0x29
local LSM303_OUT_Y_L_A         = 0x2A
local LSM303_OUT_Y_H_A         = 0x2B
local LSM303_OUT_Z_L_A         = 0x2C
local LSM303_OUT_Z_H_A         = 0x2D

local LSM303_FIFO_CTRL_REG_A   = 0x2E -- DLHC only
local LSM303_FIFO_SRC_REG_A    = 0x2F -- DLHC only

local LSM303_INT1_CFG_A        = 0x30
local LSM303_INT1_SRC_A        = 0x31
local LSM303_INT1_THS_A        = 0x32
local LSM303_INT1_DURATION_A   = 0x33
local LSM303_INT2_CFG_A        = 0x34
local LSM303_INT2_SRC_A        = 0x35
local LSM303_INT2_THS_A        = 0x36
local LSM303_INT2_DURATION_A   = 0x37

local LSM303_CLICK_CFG_A       = 0x38 -- DLHC only
local LSM303_CLICK_SRC_A       = 0x39 -- DLHC only
local LSM303_CLICK_THS_A       = 0x3A -- DLHC only
local LSM303_TIME_LIMIT_A      = 0x3B -- DLHC only
local LSM303_TIME_LATENCY_A    = 0x3C -- DLHC only
local LSM303_TIME_WINDOW_A     = 0x3D -- DLHC only

local LSM303_CRA_REG_M         = 0x00
local LSM303_CRB_REG_M         = 0x01
local LSM303_MR_REG_M          = 0x02

local LSM303_OUT_X_H_M         = 0x03
local LSM303_OUT_X_L_M         = 0x04
local LSM303_OUT_Y_H_M         = -1   -- The addresses of the Y and Z magnetometer output registers
local LSM303_OUT_Y_L_M         = -2   -- are reversed on the DLM and DLHC relative to the DLH.
local LSM303_OUT_Z_H_M         = -3   -- These four defines have dummy values so the library can
local LSM303_OUT_Z_L_M         = -4   -- determine the correct address based on the device type.

local LSM303_SR_REG_M          = 0x09
local LSM303_IRA_REG_M         = 0x0A
local LSM303_IRB_REG_M         = 0x0B
local LSM303_IRC_REG_M         = 0x0C

local LSM303_WHO_AM_I_M        = 0x0F -- DLM only

local LSM303_TEMP_OUT_H_M      = 0x31 -- DLHC only
local LSM303_TEMP_OUT_L_M      = 0x32 -- DLHC only

local LSM303DLH_OUT_Y_H_M      = 0x05
local LSM303DLH_OUT_Y_L_M      = 0x06
local LSM303DLH_OUT_Z_H_M      = 0x07
local LSM303DLH_OUT_Z_L_M      = 0x08

local LSM303DLM_OUT_Z_H_M      = 0x05
local LSM303DLM_OUT_Z_L_M      = 0x06
local LSM303DLM_OUT_Y_H_M      = 0x07
local LSM303DLM_OUT_Y_L_M      = 0x08

local LSM303DLHC_OUT_Z_H_M     = 0x05
local LSM303DLHC_OUT_Z_L_M     = 0x06
local LSM303DLHC_OUT_Y_H_M     = 0x07
local LSM303DLHC_OUT_Y_L_M     = 0x08

local MAG_ADDRESS              = (0x3C / 2)
local ACC_ADDRESS_SA0_A_LOW    = (0x30 / 2)
local ACC_ADDRESS_SA0_A_HIGH   = (0x32 / 2)


Lsm303 = class()

function Lsm303:beginTransmission( addr )
    self.i2cAddr = addr
    self.i2cBuffer = {}
end

function Lsm303:write( val )
    self.i2cBuffer[ #self.i2cBuffer + 1 ] = val
end

function Lsm303:endTransmission()
    local t = {}
    t[1] = 0
    local cnt = #self.i2cBuffer
    for i=1, cnt do
        t[i+1] = self.i2cBuffer[i]
    end
    local res = self.mcu:i2cSetAddr( self.i2cAddr )
    res = self.mcu:i2cSetAddr( self.i2cAddr )
    res = self.mcu:i2cSetBuf( unpack( t ) )
    if ( not res ) then
        return false
    end
    res = self.mcu:i2cIo( cnt, 0 )
    if ( not res ) then
        return false
    end
    res, status = self.mcu:status()
    return res, status
end

function Lsm303:requestFrom( addr, cnt )
    local res = self.mcu:i2cSetAddr( self.i2cAddr )
    res = self.mcu:i2cSetAddr( self.i2cAddr )
    res = self.mcu:i2cIo( 0, cnt )
    local t = { self.mcu:i2cBuffer( cnt ) }
    self.i2cBuffer = t
    self.i2cIndex  = 1
end

function Lsm303:read()
    local res = self.i2cBuffer[ self.i2cIndex ]
    self.i2cIndex = self.i2cIndex + 1
    return res
end

function Lsm303:__init( mcu )
    self.mcu = mcu
    -- These are just some values for a particular unit; it is recommended that
    -- a calibration be done for your particular unit.
    m_max = {}
    m_max.x = +540
    m_max.y = +500
    m_max.z = 180
    self.m_max = m_max
    m_min = {}
    m_min.x = -520
    m_min.y = -570
    m_min.z = -770
    self.m_min = {}

    self._device = LSM303_DEVICE_AUTO;
    self.acc_address = ACC_ADDRESS_SA0_A_LOW;

    self.io_timeout = 0;  -- 0 = no timeout
    self.did_timeout = false;
end

function Lsm303:init( device, sa0_a )
    self._device = device;
    if device == LSM303DLH_DEVICE or
       device == LSM303DLM_DEVICE then
        if (sa0_a == LSM303_SA0_A_LOW) then
            self.acc_address = ACC_ADDRESS_SA0_A_LOW
        elseif (sa0_a == LSM303_SA0_A_HIGH) then
            self.acc_address = ACC_ADDRESS_SA0_A_HIGH
        else
            self.acc_address = ( self:detectSA0_A() == LSM303_SA0_A_HIGH ) and ACC_ADDRESS_SA0_A_HIGH or ACC_ADDRESS_SA0_A_LOW
    elseif device == LSM303DLHC_DEVICE then
        self.acc_address = ACC_ADDRESS_SA0_A_HIGH
    else
        -- try to auto-detect device
        if ( self:detectSA0_A() == LSM303_SA0_A_HIGH) then
            -- if device responds on 0011001b (SA0_A is high), assume DLHC
            self.acc_address = ACC_ADDRESS_SA0_A_HIGH
            self._device = LSM303DLHC_DEVICE;
        else
            -- otherwise, assume DLH or DLM (pulled low by default on Pololu boards); query magnetometer WHO_AM_I to differentiate these two
            self.acc_address = ACC_ADDRESS_SA0_A_LOW
            self._device = ( self:readMagReg( LSM303_WHO_AM_I_M ) == 0x3C ) and LSM303DLM_DEVICE or LSM303DLH_DEVICE
    end
end

-- Turns on the LSM303's accelerometer and magnetometers and places them in normal
-- mode.
function Lsm303:enableDefault()
  -- Enable Accelerometer
  -- 0x27 = 0b00100111
  -- Normal power mode, all axes enabled
  self:writeAccReg( LSM303_CTRL_REG1_A, 0x27 )

  -- Enable Magnetometer
  -- 0x00 = 0b00000000
  -- Continuous conversion mode
  self:writeMagReg( LSM303_MR_REG_M, 0x00 )
}

-- Writes an accelerometer register
function Lsm303:writeAccReg( reg, value )
  self:beginTransmission( self.acc_address )
  self:write( reg )
  self:write( value )
  self.last_status = self:endTransmission()
end

-- Reads an accelerometer register
function Lsm303::readAccReg( reg )
  local value

  self:beginTransmission( self.acc_address )
  self:write( reg )
  self.last_status = self:endTransmission()
  self:requestFrom( self.acc_address, 1 )
  value = self:read()
  --Wire.endTransmission();

  return value
end

-- Writes a magnetometer register
function Lsm303::writeMagReg( reg, value )
  self:beginTransmission( MAG_ADDRESS )
  self:write( reg )
  self:write( value )
  self.last_status = self:endTransmission()
end

-- Reads a magnetometer register
function Lsm303::readMagReg( reg )
  local value

  -- if dummy register address (magnetometer Y/Z), use device type to determine actual address
  if ( reg < 0 ) then
    if res == LSM303_OUT_Y_H_M then
        reg = (self._device == LSM303DLH_DEVICE) and LSM303DLH_OUT_Y_H_M or LSM303DLM_OUT_Y_H_M
    elseif res == LSM303_OUT_Y_L_M then
        reg = (self._device == LSM303DLH_DEVICE) and LSM303DLH_OUT_Y_L_M or LSM303DLM_OUT_Y_L_M
    elseif res == LSM303_OUT_Z_H_M then
        reg = (self._device == LSM303DLH_DEVICE) and LSM303DLH_OUT_Z_H_M or LSM303DLM_OUT_Z_H_M
    elseif res == LSM303_OUT_Z_L_M then
        reg = ( self._device == LSM303DLH_DEVICE) and LSM303DLH_OUT_Z_L_M or LSM303DLM_OUT_Z_L_M;
        break;
    end
  end

  self:beginTransmission( MAG_ADDRESS )
  self:write( reg )
  self.last_status = self:endTransmission()
  self.requestFrom( MAG_ADDRESS, 1 )
  value = self:read()
  --Wire.endTransmission();

  return value
end

function Lsm303::setMagGain( value )
  self:beginTransmission( MAG_ADDRESS )
  self:write( LSM303_CRB_REG_M )
  self:write( value )
  self:endTransmission()
end

-- Reads the 3 accelerometer channels and stores them in vector a
function LSM303::readAcc()
  self:beginTransmission( self.acc_address );
  -- assert the MSB of the address to get the accelerometer
  -- to do slave-transmit subaddress updating.
  self:write( bit.or( LSM303_OUT_X_L_A, bit.lshift( 1, 7 ) ) )
  self.last_status = self:endTransmission()
  self:requestFrom( self.acc_address, 6 )

  --[[
  local millis_start = self:millis()
  did_timeout = false;
  while ( self:available() < 6 ) do
    if ( io_timeout > 0 and (millis() - millis_start) > io_timeout) then
      did_timeout = true;
      return;
    end
  end
  ]]

  local xla = self:read()
  local xha = self:read()
  local yla = self:read()
  local yha = self:read()
  local zla = self:read()
  local zha = self:read()

  -- combine high and low bytes, then shift right to discard lowest 4 bits (which are meaningless)
  -- GCC performs an arithmetic right shift for signed negative numbers, but this code will not work
  -- if you port it to a compiler that does a logical right shift instead.
  local a = {}
  a.x = bit.lshift( bit.or( bit.lshift( xha, 8 ), xla ), -4 )
  a.y = bit.lshift( bit.or( bit.lshift( yha, 8 ), yla ), -4 )
  a.z = bit.lshift( bit.or( bit.lshift( zha, 8 ), zla ), -4 )
  self.a = a
end

-- Reads the 3 magnetometer channels and stores them in vector m
function Lsm303::readMag()
  self:beginTransmission( MAG_ADDRESS )
  self:write( LSM303_OUT_X_H_M )
  self.last_status = self:endTransmission()
  self:requestFrom( MAG_ADDRESS, 6 )

  --[[
  unsigned int millis_start = millis();
  did_timeout = false;
  while (Wire.available() < 6) {
    if (io_timeout > 0 && ((unsigned int)millis() - millis_start) > io_timeout) {
      did_timeout = true;
      return;
    }
  }
  ]]

  local xhm = self:read()
  local xlm = self:read()

  local yhm, ylm, zhm, zlm;

  if ( self._device == LSM303DLH_DEVICE )
    -- DLH: register address for Y comes before Z
    yhm = self:read()
    ylm = self:read()
    zhm = self:read()
    zlm = self:read()
  else
    -- DLM, DLHC: register address for Z comes before Y
    zhm = self:read()
    zlm = self:read()
    yhm = self:read()
    ylm = self:read()
  end

  -- combine high and low bytes
  local m = {}
  m.x = bit.or( bit.lshift( xhm, 8 ), xlm )
  m.y = bit.or( bit.lshift( yhm, 8 ), ylm )
  m.z = bit.or( bit.lshift( zhm, 8 ), zlm )
  self.m = m
end

// Reads all 6 channels of the LSM303 and stores them in the object variables
void LSM303::read(void)
{
  readAcc();
  readMag();
}

// Returns the number of degrees from the -Y axis that it
// is pointing.
int LSM303::heading(void)
{
  return heading((vector){0,-1,0});
}

// Returns the number of degrees from the From vector projected into
// the horizontal plane is away from north.
//
// Description of heading algorithm:
// Shift and scale the magnetic reading based on calibration data to
// to find the North vector. Use the acceleration readings to
// determine the Down vector. The cross product of North and Down
// vectors is East. The vectors East and North form a basis for the
// horizontal plane. The From vector is projected into the horizontal
// plane and the angle between the projected vector and north is
// returned.
int LSM303::heading(vector from)
{
    // shift and scale
    m.x = (m.x - m_min.x) / (m_max.x - m_min.x) * 2 - 1.0;
    m.y = (m.y - m_min.y) / (m_max.y - m_min.y) * 2 - 1.0;
    m.z = (m.z - m_min.z) / (m_max.z - m_min.z) * 2 - 1.0;

    vector temp_a = a;
    // normalize
    vector_normalize(&temp_a);
    //vector_normalize(&m);

    // compute E and N
    vector E;
    vector N;
    vector_cross(&m, &temp_a, &E);
    vector_normalize(&E);
    vector_cross(&temp_a, &E, &N);

    // compute heading
    int heading = round(atan2(vector_dot(&E, &from), vector_dot(&N, &from)) * 180 / M_PI);
    if (heading < 0) heading += 360;
  return heading;
}

void LSM303::vector_cross(const vector *a,const vector *b, vector *out)
{
  out->x = a->y*b->z - a->z*b->y;
  out->y = a->z*b->x - a->x*b->z;
  out->z = a->x*b->y - a->y*b->x;
}

float LSM303::vector_dot(const vector *a,const vector *b)
{
  return a->x*b->x+a->y*b->y+a->z*b->z;
}

void LSM303::vector_normalize(vector *a)
{
  float mag = sqrt(vector_dot(a,a));
  a->x /= mag;
  a->y /= mag;
  a->z /= mag;
}

// Private Methods //////////////////////////////////////////////////////////////

byte LSM303::detectSA0_A(void)
{
  Wire.beginTransmission(ACC_ADDRESS_SA0_A_LOW);
  Wire.write(LSM303_CTRL_REG1_A);
  last_status = Wire.endTransmission();
  Wire.requestFrom(ACC_ADDRESS_SA0_A_LOW, 1);
  if (Wire.available())
  {
    Wire.read();
    return LSM303_SA0_A_LOW;
  }
  else
    return LSM303_SA0_A_HIGH;
}






