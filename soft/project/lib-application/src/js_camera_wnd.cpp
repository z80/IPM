
#include "js_camera_wnd.h"
#include <QtCore/QObject>
#include <QtScript/QScriptable>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>
#include "camera_wnd.h"

void JsCameraWnd::play()
{
    CameraWnd * cw = qscriptvalue_cast<CameraWnd *>( thisObject() );
    int cnt = argumentCount();
    if ( cnt > 0 )
    {
        QString stri = argument( 0 ).toString();
        cw->playFile( stri );
    }
}

void JsCameraWnd::stop()
{
    CameraWnd * cw = qscriptvalue_cast<CameraWnd *>( thisObject() );
    cw->stop();
}

bool JsCameraWnd::isPlaying()
{
    CameraWnd * cw = qscriptvalue_cast<CameraWnd *>( thisObject() );
    bool res = cw->isPlaying();
    return res;
}

void JsCameraWnd::setVolume()
{
    CameraWnd * cw = qscriptvalue_cast<CameraWnd *>( thisObject() );
    int cnt = argumentCount();
    if ( cnt > 0 )
    {
        qint32 val = argument( 0 ).toInt32();
        cw->changeVolume( val );
    }
}


