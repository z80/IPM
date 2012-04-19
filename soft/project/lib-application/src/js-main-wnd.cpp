
#include "js-main-wnd.h"
#include "main_wnd.h"
#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>

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
    QScriptValue timerCb = argument( 0 );
    bool func = timerCb.isFunction();
    MainWnd * mw = qscriptvalue_cast<MainWnd *>( thisObject() );
    qScriptConnect( mw, SIGNAL(timeout()), 0, timerCb );
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




