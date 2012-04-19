
#ifndef __JS_APPLICATION_H_
#define __JS_APPLICATION_H_

#include <QtCore/QObject>
#include <QtScript/QScriptable>

class JsMainWnd: public QObject,
                 protected QScriptable
{
    Q_OBJECT
public slots:
    void logging();
    void clear();
    void setTimerInterval( int ms );
    void setTimerEnabled( bool en );
    bool isTimerEnabled();
    void setTimerCb();
    void setInitCb();
    void setFinitCb();
};


#endif


