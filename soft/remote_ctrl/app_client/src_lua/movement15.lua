
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


local SIDES_DOWN_2  = 0x10
local SIDE_ON_2     = 0x1
local SIDES_UP_1    = 0x1
local CENTER_ON_2   = 0x4
local FORWARD_3     = 0x1
local BACKWARD_3    = 0x4
local CENTER_UP_1   = 0x10
local CENTER_DOWN_1 = 0x8 

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

    sleep( 6.0 )
    self:stToInit()
end

-- To initialized state.
function Mover:stToInit()
    print( "Going to initial position..." )
    self:forward()
    self:forward()
end


function Mover:oneStepForward()
    while true do
        self:forward()
        if ( self.state == "LoopSideSupportsDown" ) then
            break
        end
    end
end

function Mover:oneStepBackward()

    local dt = 0.3
    sleep( dt )
    remoteInvokeOutputs( { 0, CENTER_ON_2, BACKWARD_3 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, CENTER_ON_2 + SIDES_DOWN_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, CENTER_ON_2 + SIDE_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, SIDE_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_UP_1, SIDE_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, SIDE_ON_2, FORWARD_3 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_DOWN_1, SIDE_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, CENTER_ON_2 + SIDE_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, CENTER_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { SIDES_UP_1, CENTER_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, CENTER_ON_2, 0 } )
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




