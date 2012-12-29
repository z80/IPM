

function main()
   while true do
       sleep( 0.5 )
       for i = 1, 4 do
           local x, y = joy( i )
           print( string.format( "joy[%i]: %3.2f%%, %3.2f%%", i, x, y ) )
       end
       print( " " )
   end
end

function sleep( t )
    t = t or 1
    t = t * 1000
    for i=1, t do
        msleep( 1 )
    end
end

print( "client.lua loaded!!!" )
valveSetInputs( 0, 1+2+4 + 32768 )
valveSetOutputs( 0, 1+4+16 )
main()


