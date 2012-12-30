
require( "luamcuctrl" )
require( "bit" )

local BOARDS_CNT = 3
local ins = { 0, 0, 0 }

function main()
send( "print( \'host\'s entered main() dummy infinite loop\' )" )
    while true do
        sleep( 0.1 )
    end
end

function setValves( vals )
    local cnt = #vals
    for i = 1, cnt do
        ins[i] = vals[i] or 0
    end
    remoteInvokeInputs( vals )
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
        send( "print( \"Pending image is in procress. Another image capture is possible only after finishing current one.\" )" )
    else
        imgProc:start()
    end
    print( "image left" )
end

print( "host.lua loaded!!!" )
main()








