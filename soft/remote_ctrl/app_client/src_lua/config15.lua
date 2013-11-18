
local SIDES_DOWN_2  = 0x10
local SIDE_ON_2     = 0x1
local SIDES_UP_1    = 0x1
local CENTER_ON_2   = 0x4
local FORWARD_3     = 0x1
local BACKWARD_3    = 0x4
local CENTER_UP_1   = 0x10
local CENTER_DOWN_1 = 0x8 

st = 
{
    Uninitialized = 
    { 
        st = { 0, 0, 0 }, 
        nextStep="InitStep1", 
        prevStep="InitStep1", 
        delay = 0.5
    }, 

    InitStep1 = 
    { 
        -- All supports down.
        st = { CENTER_DOWN_1 + SIDES_UP_1, 0, FORWARD_3 }, 
        nextStep="InitStep2", 
        prevStep="InitStep2", 
        delay = 3.0
    }, 

    InitStep2 = 
    { 
        -- Side supprts down, both ejections on.
        st = { 0, CENTER_ON_2, 0 }, 
        nextStep="LoopSideSupportsDown", 
        prevStep="LoopSideSupportsDown", 
        delay = 3.0
    }, 


    InitStep3 = 
    { 
        -- Side supprts down, both ejections on.
        st = { 0, SIDES_DOWN_2 + CENTER_ON_2, 0 }, 
        nextStep="LoopSideSupportsDown", 
        prevStep="InitStep2", 
        delay = 1.5
    }, 

    InitStep4 = 
    { 
        -- Side supprts down, both ejections on.
        st = { 0, SIDE_ON_2 + CENTER_ON_2, 0 }, 
        nextStep="LoopSideSupportsDown", 
        prevStep="InitStep2", 
        delay = 3.0
    }, 


    LoopSideSupportsDown = 
    { 
        st = { CENTER_DOWN_1, SIDES_DOWN_2 + CENTER_ON_2, 0 }, 
        nextStep="LoopSideSuckOn", 
        prevStep="LoopSideSupportsFwd", 
        delay = 2.0
    }, 

    LoopSideSuckOn = 
    { 
        st = { 0, SIDE_ON_2 + CENTER_ON_2, 0 }, 
        nextStep="LoopCenterSuckOff", 
        prevStep="LoopSideSupportsDown", 
        delay = 2.0
    }, 

    LoopCenterSuckOff = 
    {
        st = { 0, SIDE_ON_2, 0 }, 
        nextStep="LoopCenterSupportUp", 
        prevStep="LoopSideSuckOn", 
        delay = 2.0
    },

    LoopCenterSupportUp = 
    {
        st = { CENTER_UP_1, SIDE_ON_2, 0 }, 
        nextStep="LoopSideSupportsBack", 
        prevStep="LoopCenterSuckOff", 
        delay = 3.0
    }, 

    LoopSideSupportsBack = 
    { 
        st = { 0, SIDE_ON_2, BACKWARD_3 }, 
        nextStep="LoopCenterSupportDown", 
        prevStep="LoopCenterSupportUp", 
        delay = 3.0
    }, 

    LoopCenterSupportDown = 
    {
        st = { CENTER_DOWN_1, SIDE_ON_2, 0 }, 
        nextStep="LoopCenterSuckOn", 
        prevStep="LoopSideSupportsBack", 
        delay = 3.0
    }, 

    LoopCenterSuckOn = 
    {
        st = { 0, SIDE_ON_2 + CENTER_ON_2, 0 }, 
        nextStep="LoopSideSuckOff", 
        prevStep="LoopCenterSupportDown", 
        delay = 5.0
    }, 

    LoopSideSuckOff = 
    {
        st = { 0, CENTER_ON_2, 0 }, 
        nextStep="LoopSideSupportsUp", 
        prevStep="LoopCenterSuckOn", 
        delay = 2.0
    }, 

    LoopSideSupportsUp = 
    {
        st = { SIDES_UP_1, CENTER_ON_2, 0 }, 
        nextStep="LoopSideSupportsFwd", 
        prevStep="LoopSideSuckOff", 
        delay = 2.0
    }, 

    LoopSideSupportsFwd = 
    {
        st = { 0, CENTER_ON_2, FORWARD_3 }, 
        nextStep="LoopSideSupportsDown", 
        prevStep="LoopSideSupportsUp", 
        delay = 2.0
    } 


}
return st


