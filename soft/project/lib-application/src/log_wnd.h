
#ifndef __LOG_WND_H_
#define __LOG_WND_H_

#include <QtGui>

class LogWnd: public QWidget
{
    Q_OBJECT
public:
    LogWnd( QWidget * parent = 0 );
    ~LogWnd();

    void log( const QString & stri );
    void setLinesCnt( int cnt );
    void clear();
signals:
    void sigLog( const QString & stri );
    void sigLinesCnt( int cnt );
    void sigClear();
private slots:
    void slotLog( const QString & log );
    void slotLinesCnt( int cnt );
    void slotClear();
private:
    class PD;
    PD * pd;
};

#endif



