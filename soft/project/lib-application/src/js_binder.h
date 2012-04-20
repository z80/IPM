
#ifndef __JS_BINDER_H_
#define __JS_BINDER_H_

#include <QtScript/QScriptValue>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptEngine>

class MainWnd;
class JsMainWnd;

class JsBinder: public QObject
{
public:
    JsBinder( QObject * parent = 0 );
    ~JsBinder();

    void registerMain( MainWnd * mw );
    bool run( const QString & scriptFile, int timeout = -1 );

private:
    QScriptEngine e;
    MainWnd * mainWnd;
    JsMainWnd * jsMainWnd;
};




#endif


