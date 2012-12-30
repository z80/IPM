
require( "luamcuctrl" )
require( "bit" )

local BOARDS_CNT = 3
local inputs = { 0, 0, 0 }
local emulation = true

function main()
    send( "print( \'host\'s entered main() dummy infinite loop\' )" )
    if ( emulation ) then
        emulationProcessMcu()
    else
        processMcu()
    end
end

function setValves( vals )
    ins = {}
    local cnt = #vals
    for i = 1, cnt do
        ins[i] = vals[i] or 0
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
        local ins = { mcu:inputs() }
        if ( #ins < BOARDS_CNT ) then
            -- Failure
            send( "print( \'Error: mcu doesn\'t respond on USB requests\' )" )
            mcu:close()
            sleep( 5 )
            cmu:open()
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
                break
            end
        end
        sleep( 0.1 )
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








