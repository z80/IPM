
require( "unclasslib" )

--[[
Movements are

Init should be ORed to prevent falling down from the wall
Init:
1) Side suck on
2) Side supports down

Loop steps should replace each other
Loop:
1) Side supports down, 
2) Side suck on, 
3) Center forward, 
4) Center down, 
5) Center suck on, 
6) Side suck off, 
7) Side supports up,
8) Center backward, 


]]


Mover = class()

function Mover:__init( config )
    config = config or "config15.lua"

    ch, err = loadfile( config )
    local st
    assert( ch, err )
    st = ch()
    for k, v in pairs( st ) do
        print( tostring( k ) .. "=>" .. tostring( v ) )
    end

    self.states = st
    self.state = "Uninitialized"
end

-- To initialized state.
function Mover:stToInit()
    local c = self.states
    -- Suck On
    local st = c[ "InitStep1" ]
    remoteInvokeOutputs( { st.outs[1], st.outs[2], st.outs[3] } )
    sleep( st.delay )

    -- Side supports down.
    st = c[ "InitStep2" ]
    remoteInvokeOutputs( { st.outs[1], st.outs[2], st.outs[3] } )
    sleep( st.delay )

    self.state = "InitStep2"
end

function Mover:performStepFwd()
    local c = self.states
    local st = c[ self.state ]
    local nextStep = st.nextStep

    local st = c[ nextStep ]
    print( tostring( nextStep ) )
    if ( not DEBUG ) then
        remoteInvokeOutputs( { st.st[1], st.st[2], st.st[3] } )
    end
    valveSetOutputs( 0, st.st[1] )
    valveSetOutputs( 1, st.st[2] )
    valveSetOutputs( 2, st.st[3] )
    sleep( st.delay )

    self.state = nextStep
end

function Mover:performStepBwd()
    local c = self.states
    local st = c[ self.state ]
    local prevStep = st.prevStep

    local st = c[ prevStep ]
    print( tostring( prevStep ) )
    if ( not DEBUG ) then
        remoteInvokeOutputs( { st.st[1], st.st[2], st.st[3] } )
    end
    valveSetOutputs( 0, st.st[1] )
    valveSetOutputs( 1, st.st[2] )
    valveSetOutputs( 2, st.st[3] )
    sleep( st.delay )

    self.state = prevStep
end



function Mover:forward()
    self.state = self.state or "Uninitialized"
    if ( DEBUG ) then
        print( self.state )
    end
    self:performStepFwd()
end

function Mover:backward()
    self.state = self.state or "Uninitialized"
    if ( DEBUG ) then
        print( self.state )
    end
    self:performStepBwd()
end




