
#ifndef __JS_BINDER_H_
#define __JS_BINDER_H_

#include <QtScript/QScriptValue>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptEngine>

class MainWnd;
class JsMainWnd;
class CameraWnd;
class JsCameraWnd;

class JsBinder: public QObject
{
public:
    JsBinder( QObject * parent = 0, int interval = 50 );
    ~JsBinder();

    void registerMain( MainWnd * mw );
    void registerCameraWnds( CameraWnd * intCam, CameraWnd * extCam );
    bool run( const QString & scriptFile );

private:
    QScriptEngine e;
    MainWnd * mainWnd;
    JsMainWnd * jsMainWnd;
    CameraWnd * intCam, 
              * extCam;
    JsCameraWnd * jsCamWnd;
};




#endif


