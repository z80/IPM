
#ifndef __VALVE_TST_H_
#define __VALVE_TST_H_

#include <QtGui>

class Led;
class QSwitch;

class ValveTst: public QWidget
{
    Q_OBJECT
public:
    ValveTst( QWidget * parent = 0 );
    ~ValveTst();
    
    void init( int boardsCnt = 2 );
    void clean();
    
    void setInputs( int boardInd, quint32 value );

    void setOutputs( int boardInd, quint32 value );
    quint32 outputs( int boardInd );
    
signals:
    void sigSetInputs( int, quint32 );
    void sigSetOutputs( int, quint32 );
public slots:
    void slotSetInputs( int boardInd, quint32 value );
    void slotSetOutputs( int boardInd, quint32 value );

    void slotOutChanged();
    void slotApply();
private:
    QGridLayout          * lt;
    QList<Led *>         ins;
    QList<QSwitch *>     outs;
    QList<QLabel *>      labels;
    QMutex               mutex;
    QVector<quint32>     outsV;
};




#endif



