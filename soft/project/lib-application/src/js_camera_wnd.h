

#ifndef __JS_CAMERA_WND_H_
#define __JS_CAMERA_WND_H_

#include <QtCore/QObject>
#include <QtScript/QScriptable>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>

class JsCameraWnd: public QObject,
                   protected QScriptable
{
    Q_OBJECT
public slots:
    void play();
    void stop();
    bool isPlaying();
    void setVolume();
};


#endif









