
#include "js_binder.h"
#include "main_wnd.h"
#include "js_main_wnd.h"

JsBinder::JsBinder( QObject * parent )
{
    mainWnd = 0;
    jsMainWnd = 0;
}

JsBinder::~JsBinder()
{
}

void JsBinder::registerMain( MainWnd * mw )
{
    mainWnd = mw;
    if ( !jsMainWnd )
        jsMainWnd = new JsMainWnd();
    e.setDefaultPrototype( qMetaTypeId<MainWnd*>(), e.newQObject(jsMainWnd) );
    e.globalObject().setProperty( "mainWnd", e.newQObject( mainWnd ) );
}

bool JsBinder::run( const QString & fileName, int timeout )
{
     QFile scriptFile( fileName );
     scriptFile.open(QIODevice::ReadOnly);
     QTextStream stream( &scriptFile );
     QString contents = stream.readAll();
     scriptFile.close();

     e.setProcessEventsInterval( timeout );
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




