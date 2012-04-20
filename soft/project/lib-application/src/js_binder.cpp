
#include "js_binder.h"
#include "main_wnd.h"
#include "js_main_wnd.h"
#include "camera_wnd.h"
#include "js_camera_wnd.h"

JsBinder::JsBinder( QObject * parent, int interval )
{
    mainWnd = 0;
    jsMainWnd = 0;
    jsCamWnd = 0;
    e.setProcessEventsInterval( interval );
}

JsBinder::~JsBinder()
{
    //if ( jsMainWnd )
    //    jsMainWnd->deleteLater();
    //if ( jsCamWnd )
    //    jsCamWnd->deleteLaer();
}

void JsBinder::registerMain( MainWnd * mw )
{
    mainWnd = mw;
    if ( !jsMainWnd )
        jsMainWnd = new JsMainWnd();
    e.setDefaultPrototype( qMetaTypeId<MainWnd*>(), e.newQObject(jsMainWnd) );
    e.globalObject().setProperty( "mainWnd", e.newQObject( mainWnd ) );
}

void JsBinder::registerCameraWnds( CameraWnd * intCam, CameraWnd * extCam )
{
    this->intCam = intCam;
    this->extCam = extCam;
    if ( !jsCamWnd )
        jsCamWnd = new JsCameraWnd();
    e.setDefaultPrototype( qMetaTypeId<CameraWnd*>(), e.newQObject( jsCamWnd ) );
    e.globalObject().setProperty( "intCamWnd", e.newQObject( intCam ) );
    e.globalObject().setProperty( "extCamWnd", e.newQObject( extCam ) );
}

bool JsBinder::run( const QString & fileName )
{
     QFile scriptFile( fileName );
     scriptFile.open(QIODevice::ReadOnly);
     QTextStream stream( &scriptFile );
     QString contents = stream.readAll();
     scriptFile.close();

     QScriptValue result = e.evaluate( contents, fileName );
     bool res = !result.isError();
     if ( !res )
     {
         QMessageBox::critical( 0, fileName,
                                QString::fromLatin1( "%0:%1: %2" )
                               .arg( fileName )
                               .arg( result.property( "lineNumber" ).toInt32() )
                               .arg( result.toString()) );
     }
     return res;
}

bool JsBinder::runText( const QString & script )
{
     QScriptValue result = e.evaluate( script );
     bool res = !result.isError();
     if ( !res )
     {
         QMessageBox::critical( 0, "script",
                                QString::fromLatin1( "%0:%1: %2" )
                               .arg( "script" )
                               .arg( result.property( "lineNumber" ).toInt32() )
                               .arg( result.toString()) );
     }
     return res;
}

void JsBinder::stop()
{
    e.abortEvaluation();
}




