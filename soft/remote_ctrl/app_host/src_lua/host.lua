
require( "luamcuctrl" )
require( "bit" )


function main()
    send( print( "host\'s entered main() dummy infinite loop" ) )
    while true do
        sleep( 100 )
    end
end

function sleep( msec )
    msec = ( msec < 10000 ) and msec or 10000
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








