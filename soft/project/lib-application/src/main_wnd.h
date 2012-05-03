
#ifndef __MAIN_WND_H_
#define __MAIN_WND_H_

#include <QtGui>

class MainWnd: public QMainWindow
{
    Q_OBJECT
public:
    MainWnd( QWidget * parent = 0 );
    virtual ~MainWnd();

    void log( const QString & stri );
    void clear();
    void setTimerInterval( int ms );
    void setTimerEnabled( bool en );
    bool isTimerEnabled() const;
protected:
    bool eventFilter( QObject * o, QEvent * e );
signals:
    void timeout();
private:
    class PD;
    PD * pd;
};

Q_DECLARE_METATYPE( MainWnd * )

#endif



