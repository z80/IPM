
require( "luajoyctrl" )
require( "bit" )
require( "movement" )
-- require( "debugger" )

-- This value is supposed to detach real output
-- and turn some test information on.
DEBUG = true
local JOY_TRESHOLD = 10

local BOARDS_CNT = 3
local valves = { 0, 0, 0 }

function main()
    print( "Initializing valve test window" )
    for i=1, BOARDS_CNT do
        valveSetInputs( i-1, 0 )
        valveSetOutputs( i-1, 0 )
    end
    mov = Mover()

    while true do
        sleep( 0.1 )
        if ( not DEBUG ) then
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
        end
        -- Process joysticks.
        --joyProcess( valves )
        local turn, fwd = joy( 1 )
        print( "fwd = " .. tostring( fwd ) )
        if ( fwd > JOY_TRESHOLD ) then
            --pause()
            res, err = pcall( mov.forward, mov )
            if ( not res ) then
                print( err )
            end
        elseif ( fwd < -JOY_TRESHOLD ) then
            --pause()
            res, err = pcall( mov.backward, mov )
            if ( not res ) then
                print( err )
            end
        end
        -- Process spinning
        --[[
        prevSpinDir = prevSpinDir or "idle"
        if ( turn > JOY_TRESHOLD ) then
            if ( prevSpinDir and prevSpinDir ~= "cw" ) then
                if ( DEBUG ) then
                    print( "cw" )
                end
                prevSpinDir = "cw"
                send( "bmsd:move( 10, 90, 90 )" )
                send( "bmsd:start()" )
            end
        elseif ( turn < -JOY_TRESHOLD ) then
            if ( prevSpinDir and prevSpinDir ~= "ccw" ) then
                if ( DEBUG ) then
                    print( "ccw" )
                end
                prevSpinDir = "ccw"
                send( "bmsd:move( -10, 90, 90 )" )
                send( "bmsd:start()" )
            end
        else
            if ( prevSpinDir and prevSpinDir ~= "idle" ) then
                if ( DEBUG ) then
                    print( "idle" )
                end
                prevSpinDir = "idle"
                send( "bmsd:stop()" )
            end
        end
        ]]

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

function joyProcess( valves )
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
    local adcX = {}
    local adcY = {}
    local nullX = {}
    local nullY = {}
    local stopBtn

    stopByn = j:stopBtn()
    print( string.format( "stopBtn: %s", stopBtn and "true" or "false" ) )

    for i=0, 3 do
        adcX[i+1]  = j:adcX( i )
        adcY[i+1]  = j:adcY( i )
        nullX[i+1] = j:nullX( i )
        nullY[i+1] = j:nullY( i )
        print( string.format( "adcX[%i]: %3i; adcY[%i]: %3i; nullX: %s, nullY: %s", 
                              i,  
                              adcX[i+1], 
                              i, 
                              adcY[i+1], 
                              nullX[i+1] and "true" or "false", 
                              nullY[i+1] and "true" or "false" ) )
    end

    -- 0-th joystick controls 0 and 1 outputs depending on where 
    -- it is bended, to the left or to the right.
    local valve = valves[0]
    if ( adcX[0] < 1024 ) then
        valve = bit.bor( valve, 1 )
    elseif ( adcX[0] > 3072 ) then
        valve = bit.bor( valve, 2 )
    else
        valve = bit.band( valve, 0xFFFFFFFF - 3 )
    end
    -- the same with 2 and 3 outs. They are 
    -- made dependant on Y axis of 0-th joystick.
    if ( adcY[0] < 1024 ) then
        valve = bit.bor( valve, 4 )
    elseif ( adcY[0] > 3072 ) then
        valve = bit.bor( valve, 8 )
    else
        valve = bit.band( valve, 0xFFFFFFFF - 12 )
    end
 
    if ( valve ~= valves[0] ) then
        valves[0] = valve
        remoteInvokeOutputs( valves )
    end
end



main()


