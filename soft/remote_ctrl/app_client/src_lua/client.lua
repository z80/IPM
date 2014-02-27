
require( "luajoyctrl" )
require( "bit" )
--require( "movement15" )
require( "movement50" )
-- require( "debugger" )

-- This value is supposed to detach real output
-- and turn some test information on.
--DEBUG = true

local JOY_TRESHOLD = 25

local BOARDS_CNT = 3
local valves = { 0, 0, 0 }

local escon_started = {}

function main()
    print( "Initializing valve test window" )
    for i=1, BOARDS_CNT do
        valveSetInputs( i-1, 0 )
        valveSetOutputs( i-1, 0 )
    end
    mov = Mover()
    
    -- ESCON controllers initialization.
    --initEscon()

    while true do
        sleep( 0.1 )
        --[[
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
        ]]

        --print( "Before joysticks" )
        -- Process joysticks.
        if ( not DEBUG ) then
            joyProcess( valves )
        end
        
        local zeroSpin = false
        local turn, fwd = joyVal( 1 )
        --print( "fwd = " .. tostring( fwd ) )
        if ( fwd < -JOY_TRESHOLD ) then
            --pause()
            zeroSpin = true
            print( "Forward step" )
            res, err = pcall( mov.oneStepForward, mov )
            if ( not res ) then
                print( err )
            end
        elseif ( fwd > JOY_TRESHOLD ) then
            --pause()
            zeroSpin = true
            print( "Backward step" )
            res, err = pcall( mov.oneStepBackward, mov )
            if ( not res ) then
                print( err )
            end
        end
        -- Process spinning
       
        --print( "Here 01" )
        if ( zeroSpin ) then
            turn = 0.0
        end
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

        --print( "Here 02" )
        -- Process manipulator.
        local hor, vert = joyVal( 3 )

        --print( string.format( "hor = %s, ver = %s", tostring( hor ), tostring( vert ) ) )
        --print( "Here 02.5" )
        esconSetSpeed( 1, hor )
        --print( "Here 02.75" )
        esconSetSpeed( 2, vert )
        
        --print( "Here 03" )
        local hor, vert = joyVal( 4 )
        esconSetSpeed( 3, vert )


        
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

    stopBtn = j:stopBtn()
    
    
    --print( string.format( "stopBtn: %s", stopBtn and "true" or "false" ) )

    --print( "Joystick table" )
    joyValues = joyValues or {}
    for i=0, 3 do
        adcX[i+1]  = j:adcX( i )
        adcY[i+1]  = j:adcY( i )
        nullX[i+1] = j:nullX( i )
        nullY[i+1] = j:nullY( i )
        --[[
        print( string.format( "adcX[%i]: %3i; adcY[%i]: %3i; nullX: %s, nullY: %s", 
                              i,  
                              adcX[i+1], 
                              i, 
                              adcY[i+1], 
                              nullX[i+1] and "true" or "false", 
                              nullY[i+1] and "true" or "false" ) )
        ]]
        
        local y = (adcX[i+1] - 511) * 100 / 512
        local x = (adcY[i+1] - 511) * 100 / 512
        joyValues[ i+1 ] = { x = x, y = y }
        print( string.format( "k[%i]=%i, %i", i, joyValues[i+1].x, joyValues[i+1].y ) )
    end

    --[[
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
    ]]
end

function initEscon()
    send( "escon:setSpeed( 1, 0 )" )
    send( "escon:start( 1 )" )
    
    send( "escon:setSpeed( 2, 0 )" )
    send( "escon:start( 2 )" )
    
    send( "escon:setSpeed( 3, 0 )" )
    send( "escon:start( 3 )" )
    
    send( "escon:setSpeed( 4, 0 )" )
    send( "escon:start( 4 )" )
end

function startStopEscon( ind, val )
    --print( "startStop entered" )
    --print( string.format( "ind = %s, val = %s", tostring(ind), tostring(val) ) )
    if ( math.abs( val ) > JOY_TRESHOLD ) then
        --print( "startStop start" )
        if ( not escon_started[ ind ] ) then
            escon_started[ ind ] = true
            send( string.format( "escon:start( %i )", ind ) )
        end
        --print( "startStop left" )
        return true
    else
        --print( "startStop stop" )
        if ( escon_started[ ind ] ) then
            escon_started[ ind ] = false
            send( string.format( "escon:stop( %i )", ind ) )
        end
    end
    return false
end

function joyToSpeed( val )
    local a = math.abs( val )
    if (  a < JOY_TRESHOLD ) then
        return 0
    end
    local s = 100 / (100 - JOY_TRESHOLD)
    if ( val > 0 ) then
        return s*(a - JOY_TRESHOLD)
    else
        return s*(JOY_TRESHOLD - a)
    end
end

function esconSetSpeed( ind, val )
    if ( startStopEscon( ind, val ) ) then
        --print( string.format( "setSpeed %s", tostring( val ) ) )
        local speed = joyToSpeed( val )
        --print( "after joyToSpeed" )
        local stri = string.format( "escon:setSpeed( %i, %i )", ind, val )
        send( stri )
    end
end

function joyVal( ind )
    if ( DEBUG ) then
        local x, y = joy( ind )
        return x, y
    end
    
    x, y = joyValues[ ind ].x, joyValues[ ind ].y
    return x, y
end



main()


