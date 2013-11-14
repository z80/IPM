
st = 
{
    Uninitialized = 
    { 
        st = { 123, 321, 312 }, 
        nextStep="InitStep1", 
        prevStep="InitStep1", 
        delay = 0.5
    }, 

    InitStep1 = 
    { 
        st = { 123, 321, 312 }, 
        nextStep="InitStep2", 
        prevStep="InitStep2", 
        delay = 3.0
    }, 

    InitStep2 = 
    { 
        st = { 123, 321, 312 }, 
        nextStep="LoopSideSupportsDown", 
        prevStep="LoopSideSupportsDown", 
        delay = 2.0
    }, 

    LoopSideSupportsDown = 
    { 
        st = { 123, 321, 312 }, 
        nextStep="LoopSideSuckOn", 
        prevStep="LoopSideSupportsFwd", 
        delay = 2.0
    }, 

    LoopSideSuckOn = 
    { 
        st = { 123, 321, 312 }, 
        nextStep="LoopCenterSuckOff", 
        prevStep="LoopSideSupportsDown", 
        delay = 4.0
    }, 

    LoopCenterSuckOff = 
    {
        st = { 1, 2, 3 }, 
        nextStep="LoopCenterSupportUp", 
        prevStep="LoopSideSuckOn"
    },

    LoopCenterSupportUp = 
    {
        st = { 1, 2, 3 }, 
        nextStep="LoopSideSupportsBack", 
        prevStep="LoopCenterSuckOff", 
        delay = 3.0
    }, 

    LoopSideSupportsBack = 
    { 
        st = { 1, 1, 1 }, 
        nextStep="LoopCenterSupportDown", 
        prevStep="LoopCenterSupportUp", 
        delay = 3.0
    }, 

    LoopCenterSupportDown = 
    {
        st = { 1, 1, 1 }, 
        nextStep="LoopCenterSuckOn", 
        prevStep="LoopSideSupportsBack", 
        delay = 4.0
    }, 

    LoopCenterSuckOn = 
    {
        st = { 1, 1, 1 }, 
        nextStep="LoopSideSuckOff",
        prevStep="LoopCenterSupportDown", 
        delay = 5.0
    }, 

    LoopSideSuckOff = 
    {
        st = { 1, 1, 1 }, 
        nextStep="LoopSideSupportsUp", 
        prevStep="LoopCenterSuckOn", 
        delay = 3.0
    }, 

    LoopSideSupportsUp = 
    {
        st = { 1, 1, 1 }, 
        nextStep="LoopSideSupportsFwd", 
        prevStep="LoopSideSuckOff"
    }, 

    LoopSideSupportsFwd = 
    {
        st = { 1, 1, 1 }, 
        nextStep="LoopSideSupportsDown", 
        prevStep="LoopSideSupportsUp", 
        delay = 3.0
    } 


}
return st


