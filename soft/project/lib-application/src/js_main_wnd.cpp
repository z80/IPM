
#include "js_main_wnd.h"
#include "main_wnd.h"

void JsMainWnd::logging()
{
    MainWnd * mw = qscriptvalue_cast<MainWnd *>( thisObject() );
    int cnt = argumentCount();
    for ( int i=0; i<cnt; i++ )
    {
        QScriptValue val = argument( 0 );
        mw->log( val.toString() );
    }
}

void JsMainWnd::clear()
{
    MainWnd * mw = qscriptvalue_cast<MainWnd *>( thisObject() );
    mw->clear();
}

void JsMainWnd::setTimerInterval( int ms )
{
    MainWnd * mw = qscriptvalue_cast<MainWnd *>( thisObject() );
    mw->setTimerInterval( ms );
}

void JsMainWnd::setTimerEnabled( bool en )
{
    MainWnd * mw = qscriptvalue_cast<MainWnd *>( thisObject() );
    mw->setTimerEnabled( en );
}

bool JsMainWnd::isTimerEnabled()
{
    MainWnd * mw = qscriptvalue_cast<MainWnd *>( thisObject() );
    bool res = mw->isTimerEnabled();
    return res;
}

void JsMainWnd::setTimerCb()
{
    int cnt = argumentCount();
    if ( cnt < 1 )
        return;
    QScriptValue cb;
    QScriptValue context;
    if ( cnt > 1 )
    {
        context = argument( 0 );
        cb = argument( 1 );
    }
    else
        cb = argument( 0 );
    MainWnd * mw = qscriptvalue_cast<MainWnd *>( thisObject() );
    
    if ( !timerCb.isNull() )
        qScriptDisconnect( mw, SIGNAL(timeout()), timerCbContext, timerCb );
    timerCb        = cb;
    timerCbContext = context;
    if ( !cb.isFunction() )
        return;
    qScriptConnect( mw, SIGNAL(timeout()), context, cb );
}

void JsMainWnd::setInitCb()
{
    QScriptValue timerCb = argument( 0 );
    MainWnd * mw = qscriptvalue_cast<MainWnd *>( thisObject() );
    qScriptConnect( mw, SIGNAL(timeout()), 0, timerCb );
}

void JsMainWnd::setFinitCb()
{
    QScriptValue timerCb = argument( 0 );
    MainWnd * mw = qscriptvalue_cast<MainWnd *>( thisObject() );
    qScriptConnect( mw, SIGNAL(timeout()), 0, timerCb );
}




