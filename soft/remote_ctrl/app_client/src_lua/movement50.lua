
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


local CENTER_ON_1  = 0x4+0x8
local SIDES_DOWN_2 = 0x4
local SIDES_UP_3   = 0x1
local SIDES_ON_2   = 0x1
local FORWARD_3    = 0x40
local BACKWARD_3   = 0x800
local CENTER_UP_3  = 0x400
local CENTER_DOWN_3 = 0x80




Mover = class()

function Mover:__init( config )
    sleep( 6.0 )
    self:stToInit()
end

-- To initialized state.
function Mover:stToInit()
    print( "Going to initial position..." )
    local dt = 0.3
    sleep( dt )
    remoteInvokeOutputs( { 0, 0, FORWARD_3 + CENTER_DOWN_3 + SIDES_UP_3 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, 0, 0 } )
end


function Mover:oneStepForward()
    local dt = 0.3
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, SIDES_DOWN_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, SIDES_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, SIDES_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, SIDES_ON_2, CENTER_UP_3 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, SIDES_ON_2, BACKWARD_3 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, SIDES_ON_2, CENTER_DOWN_3 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, SIDES_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, 0, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, 0, SIDES_UP_3 } ) 
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, 0, FORWARD_3 } ) 
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, 0, 0 } ) 
end

function Mover:oneStepBackward()
    local dt = 0.3
    sleep( dt )
    remoteInvokeOutputs( { 0, SIDES_ON_2, FORWARD_3 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, SIDES_DOWN_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, SIDES_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, SIDES_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, SIDES_ON_2, CENTER_UP_3 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, SIDES_ON_2, BACKWARD_3 } )
    sleep( dt )
    remoteInvokeOutputs( { 0, SIDES_ON_2, CENTER_DOWN_3 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, SIDES_ON_2, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, 0, 0 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, 0, SIDES_UP_3 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, 0, FORWARD_3 } )
    sleep( dt )
    remoteInvokeOutputs( { CENTER_ON_1, 0, 0 } )
end





