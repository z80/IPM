
timerCb = function()
{
    mainWnd.logging( "timeout " + String( ind ) );
    ind = ind + 1;
    if ( ind > 20 )
    {
        ind = 0;
        mainWnd.clear();
    }
}

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


