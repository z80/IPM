
require( "bit" )
--require( "lsm303" )
require( "bmsd" )
require( "escon" )
require( "absenc" )

function display( ... )
    local t = { ... }
    for i=1, #t do
        local stri = string.format( "print( \'arg[%i] = %s\' )", i, tostring( t[i] ) )
	send( stri )
    end
end

local BOARDS_CNT = 3
local inputs = { 0, 0, 0 }
local emulation = false

function main()
    while ( not isConnected() ) do
        sleep( 10 )
        if ( not isConnected() ) then
            connect()
        end
    end
    send( "print( \"host\'s entered main() dummy infinite loop\" )" )
    if ( emulation ) then
        emulationProcessMcu()
    else
        processMcu()
    end
end

function setValves( vals )
    if ( emulation ) then
        ins = {}
        local cnt = #vals
        for i = 1, cnt do
            ins[i] = (vals[i] or 0) * 2
        end
    else
        if ( mcu and mcu:isOpen() ) then
            vals = vals or {}
            mcu:setOutputs( unpack( vals ) )
        else
            send( "print( \'ERROR: mcu is not present or is not open\' )" )
        end
    end
end

function remoteInvokeInputs( vals )
    local stri = "send( setInputs( { "
    local cnt = #vals
    for i=1, cnt do
        stri = stri .. tostring( vals[i] or 0 )
        if ( i ~= cnt ) then
            stri = stri .. ", "
        else
            stri = stri .. " "
        end
    end
    stri = stri .. "} ) )"
    send( stri )
end

function processMcu()
    -- mcu variable is NOT local to be accessible from the outside.
    mcu = luamcuctrl.create()
    bmsd = BMSD( mcu )
    escon = ESCON( mcu )
    -- Accelerometer class.
    -- It is for the very first run and probably doesn't work at all.
    --lsm303 = Lsm303( mcu )
    encabs = Absenc()

    local en = mcu:open()
    if ( en ) then
        send( "print( \'Opended MCU successfully\' )" )
	      mcu:accInit()
        encabsConfig( 12, 16 )
    else
        send( "print( \"ERROR: MCU can\'t be open\" )" )
    end
    while true do
        local ins
        if ( mcu and mcu:isOpen() ) then
            ins = { mcu:inputs( BOARDS_CNT ) }
        else
            ins = {}
        end
        if ( #ins < BOARDS_CNT ) then
            -- Failure
            send( "print( \"Error: mcu doesn\'t respond on USB requests\" )" )
            mcu:close()
            sleep( 5 )
            local res = mcu:open()
	          if ( res ) then
                mcu:accInit()
	          end
        else
            -- Success.
            -- Compare current inputs with their new values from MCU.
            for i = 1, BOARDS_CNT do
                if ( inputs[i] ~= ins[i] ) then
                    for i = 1, BOARDS_CNT do
                        inputs[i] = ins[i]
                    end
                    remoteInvokeInputs( inputs )
                    break
                end
            end
	    --print( "here" )
        end
        sleep( 0.1 )
    end
end

function emulationProcessMcu()
    ins = {}
    while true do
        for i = 1, BOARDS_CNT do
            ins[i] = ins[i] or 0
            if ( inputs[i] ~= ins[i] ) then
                for i = 1, BOARDS_CNT do
                    inputs[i] = ins[i]
                end
                remoteInvokeInputs( inputs )
                send( "print( \'Updated inputs\' )" )
                break
            end
        end
        sleep( 0.1 )
    end
end

--[[
    To understand what's going on call report() function.
]]
function report()
    local stri = string.format( "print( \"mcu = %s\" )", tostring( mcu ) )
    send( stri )
    if ( mcu ) then
        stri = string.format( "print( \"mcu:isOpen() = %s\" )", mcu:isOpen() and "true" or "false" )
        send( stri )
    end
end

function reportAcc()
    local res, x, y, z = mcu:accAcc()
    local striAcc
    if ( res ) then
        striAcc = string.format( "setAcc( %6i, %6i, %6i )", x, y, z )
    else
        striAcc = "print( \'acc: error\' )"
    end

    local striMag
    res, x, y, z = mcu:accMag()
    if ( res ) then
        striMag = string.format( "setMag( %6i, %6i, %6i )", x, y, z )
    else
        striMag = "print( \'mag: error\' )"
    end

    local striTemp
    res, x = mcu:accTemp()
    if ( res ) then
        striTemp = string.format( "setTemp( %6i )", x )
    else
        striTemp = string.format( "print( \'t: error\' )" )
    end

    send( striAcc )
    send( striMag )
    send( striTemp )
end

acc = reportAcc

function reportInputs()
    local ins
    if ( mcu and mcu:isOpen() ) then
        ins = { mcu:inputs( BOARDS_CNT ) }
    else
        ins = {}
    end
    if ( #ins < BOARDS_CNT ) then
        -- Failure
        send( "print( \"Error: mcu doesn\'t respond on USB requests\" )" )
        mcu:close()
        sleep( 5 )
        local res = mcu:open()
	if ( res ) then
            mcu:accInit()
	end
    else
        -- Success.
        -- Compare current inputs with their new values from MCU.
        for i = 1, BOARDS_CNT do
            inputs[i] = ins[i]
        end
	local stri = string.format( "print( \'%i, %i, %i\' )", ins[1] or 0, ins[2] or 0, ins[3] or 0 )
	send( stri )
        remoteInvokeInputs( inputs )
    end
end

function sleep( sec )
    sec = ( sec < 10 ) and sec or 10
    msec = sec * 1000
    for i=1, msec, 50 do
        msleep( 50 )
    end
end

function image( w, h )
    print( "image entered" )
    client = true
    if ( not imgProc ) then
        imgProc = luafsw.create()
        imgProc:setPeer( peer() )
    end
    if ( imgProc:isRunning() ) then
        send( "print( \"Pending image is in process. Another image capture is possible only after finishing current one.\" )" )
    else
        imgProc:start()
    end
    print( "image left" )
end

function valveTest( tOn, tOff, cnt )
    local vOn  = { 1, 0, 0 }
    local vOff = { 0, 0, 0 }
    cnt = cnt or 3
    tOn = tOn or 0.1
    tOff = tOff or 0.1
    for i=1, cnt do
        setValves( vOn )
        sleep( tOn )
        setValves( vOff )
        sleep( tOff )
    end
    send( "print( \'Done\' )" )
end

function encabsConfig( bits, delay )
  bits  = bits  or 12
  delay = delay or 16
  encabs:setBits( bits )
  encabs:setDelay( delay )
end

print( "host.lua loaded!!!" )
main()
