
#ifndef __VALVE_TST_H_
#define __VALVE_TST_H_

#include <QtGui>

class Led;

class ValveTst: public QWidget
{
    Q_OBJECT
public:
    ValveTst( QWidget * parent = 0 );
    ~ValveTst();

    void init( int boardsCnt = 2 );
    void clean();

    void setInputs( int boardInd, quint32 value );
    void outputs( int boardInd, quint32 value );
public slots:
    void slotApply();
    void slotOutChanged();
private:
    QGridLayout          * lt;
    QList<Led *>         ins;
    QList<QPushButton *> outs;
};




#endif



