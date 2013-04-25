
require( "luajoyctrl" )


local BOARDS_CNT = 3
local valves = { 0, 0, 0 }

function main()
    print( "Initializing valve test window" )
    for i=1, BOARDS_CNT do
        valveSetInputs( i-1, 0 )
        valveSetOutputs( i-1, 0 )
    end

    while true do
        sleep( 0.1 )
        -- Valve test window outputs query
        for i=1, BOARDS_CNT do
            local valve = valveOutputs( i-1 )
            -- If not equal
            if ( valve ~= valves[i] ) then
                -- Apply all changes.
                for i = 1, BOARDS_CNT do
                    local valve = valveOutputs( i-1 )
                    valves[i] = valve
                end
                -- Send to host.
                remoteInvokeOutputs( valves )
                -- Break comparing.
                break
            end
        end
	-- Process joysticks.
        joyProcess()

        --[[for i = 1, 4 do
            local x, y = joy( i )
            --print( string.format( "joy[%i]: %3.2f%%, %3.2f%%", i, x, y ) )
        end
        print( " " )]]
    end
end

function sleep( t )
    t = t or 1
    t = t * 1000
    for i=1, t do
        msleep( 1 )
    end
end

function remoteInvokeOutputs( vals )
    local stri = "send( setValves( { "
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

function setInputs( vals )
    local cnt = #vals
    for i = 1, cnt do
        valveSetInputs( i-1, vals[i] )
    end
end

function setAcc( x, y, z )
    print( string.format( "acc: %i, %i, %i", x, y, z ) )
end

function setMag( x, y, z )
    print( string.format( "mag: %i, %i, %i", x, y, z ) )
end

function setTemp( t )
    print( string.format( "temp: %i", t ) )
end

function joyProcess()
    --print( "Entered joyProcess()" )
    if ( not joystick ) then
        --print( "one" )
        local j = luajoyctrl.create()
	j:open()
	joystick = j
    end
    local j = joystick
    --print( "two" )
    if ( not j:isOpen() ) then
        --print( "three" )
        j:open()
    end
    if ( not j:isOpen() ) then
        print( "ERROR: no joysticks board detected!" )
        return
    end
    j:queryState()
    local adc = {}
    local nullX = {}
    local nullY = {}
    local stopBtn

    stopByn = j:stopBtn()
    print( string.format( "stopBtn: %s", stopBtn and "true" or "false" ) )

    for i=0, 3 do
        adc[i+1]   = j:joy( i )
	nullX[i+1] = j:nullX( i )
	nullY[i+1] = j:nullY( i )
	print( string.format( "adc[%i]: %3i; nullX: %s, nullY: %s", 
	                          i,  
	                          adc[i+1], 
				  nullX[i+1] and "true" or "false", 
				  nullY[i+1] and "true" or "false" ) )
    end
end



main()


