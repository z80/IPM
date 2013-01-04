
require( "bit" )

local BOARDS_CNT = 3
local inputs = { 0, 0, 0 }
local emulation = false

function main()
    --while ( not isConnected() ) do
    --    sleep( 5 )
    --    if ( not isConnected() ) then
    --        connect()
    --    end
    --end
    send( "print( \'host\'s entered main() dummy infinite loop\' )" )
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
    local en = mcu:open()
    while true do
        local ins
        if ( mcu and mcu:isOpen() ) then
            ins = { mcu:inputs( BOARDS_CNT ) }
        else
            ins = {}
        end
        if ( #ins < BOARDS_CNT ) then
            -- Failure
            send( "print( \'Error: mcu doesn\'t respond on USB requests\' )" )
            mcu:close()
            sleep( 5 )
            mcu:open()
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

print( "host.lua loaded!!!" )
main()








