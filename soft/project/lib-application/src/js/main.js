
timerCb = function()
{
    mainWnd.logging( "timeout " + String( ind ) );
    ind = ind + 1;
    if ( ind > 20 )
    {
        ind = 0;
        mainWnd.clear();
    }
    mainWnd.logging( "internal isPlaying = " + String( intCamWnd.isPlaying() ) )
    mainWnd.logging( "external isPlaying = " + String( extCamWnd.isPlaying() ) )
}

intCamWnd.play( "./tide.mpg" )
extCamWnd.play( "./tide.mpg" )

ind = 0;
mainWnd.logging( "entered" );
mainWnd.setTimerCb( timerCb );
mainWnd.setTimerCb( timerCb );
mainWnd.setTimerCb( timerCb );
mainWnd.setTimerCb( timerCb );
mainWnd.setTimerCb( timerCb );
mainWnd.setTimerCb( timerCb );
mainWnd.setTimerInterval( 500 );
mainWnd.setTimerEnabled( true );
mainWnd.logging( 'left' );


