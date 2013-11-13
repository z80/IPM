
st = 
{
    Unitialized = 
    { 
        st = { 123, 321, 312 }, 
        nextStep="InitStep1", 
	prevStep="InitStep1" 
    }, 

    InitStep1 = 
    { 
        st = { 123, 321, 312 }, 
        nextStep="InitStep2", 
	prevStep="InitStep2" 
    }, 

    InitStep2 = 
    { 
        st = { 123, 321, 312 }, 
        nextStep="LoopSideSupportsDown", 
	prevStep="LoopSideSupportsDown" 
    }, 

    LoopSideSupportsDown = 
    { 
        st = { 123, 321, 312 }, 
        nextStep="LoopSideSuckOn", 
	prevStep="LoopSideSupportsFwd" 
    }, 

    LoopSideSuckOn = 
    { 
        st = { 123, 321, 312 }, 
        nextStep="LoopSideSupportsBack", 
        prevStep="LoopSideSupportsDown" 
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
	prevStep="LoopCenterSuckOff"
    }, 

    LoopSideSupportsBack = 
    { 
        st = { 1, 1, 1 }, 
	nextStep="LoopCenterSupportDown", 
	prevStep="LoopSideSuckOn", 
    }, 

    LoopCenterSupportDown = 
    {
        st = { 1, 1, 1 }, 
	nextStep="LoopCenterSuckOn", 
	prevStep="LoopSizeSupportsBack" 
    }, 

    LoopCenterSuckOn = 
    {
        st = { 1, 1, 1 }, 
	nextStep="LoopSideSuckOff",
	prevStep="LoopCenterSupportDown", 
    }, 

    LoopSideSuckOff = 
    {
        st = { 1, 1, 1 }, 
	nextStep="LoopSideSupportsUp", 
	prevStep="LoopCenterSuckOn", 
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
	prevStep="LoopSideSupportsUp"
    } 


}
return st


