
#include "valve_tst.h"
#include "led.h"
#include "qswitch.h"

ValveTst::ValveTst( QWidget * parent )
: QWidget( parent )
{
    lt = new QGridLayout( this );
    lt->setSpacing( 1 );
    lt->setMargin( 1 );
    connect( this, SIGNAL(sigSetInputs(int, quint32)),  this, SLOT(slotSetInputs(int, quint32)), Qt::QueuedConnection );
    connect( this, SIGNAL(sigSetOutputs(int, quint32)), this, SLOT(slotSetOutputs(int, quint32)), Qt::QueuedConnection );
    init( 3 );
    setWindowTitle( "Valve test window" );
    setWindowFlags( Qt::Tool );
}

ValveTst::~ValveTst()
{
    lt->deleteLater();
}

void ValveTst::init( int boardsCnt )
{
    clean();
    for ( int i=0; i<boardsCnt; i++ )
    {
        for ( int j=0; j<16; j++ )
        {
            Led * led = new Led( this );
            led->setMinimumSize( QSize( 32, 32 ) );
            led->setMaximumSize( QSize( 32, 32 ) );
            lt->addWidget( led, i*2, 16+j );
            ins << led;
        }
        for ( int j=0; j<32; j++ )
        {
            QSwitch * b = new QSwitch( this );
            b->setMaximumSize( QSize( 32, 32 ) );
            b->setMinimumSize( QSize( 32, 32 ) );
            connect( b, SIGNAL(valueChanged(bool)), this, SLOT(slotOutChanged()) );
            lt->addWidget( b, 2*i+1, j );
            outs << b;
        }
    }
    outsV.resize( boardsCnt );
    for ( int j=0; j<32; j++ )
    {
        QLabel * l = new QLabel( this );
        l->setText( QString( "%1" ).arg( 31 - j ) );
        lt->addWidget( l, boardsCnt*2, j );
        labels << l;
    }
}

void ValveTst::clean()
{
    while ( ins.size() > 0 )
    {
        Led * l = ins.front();
        ins.pop_front();
        l->deleteLater();
    }
    while ( outs.size() > 0 )
    {
        QSwitch * b = outs.front();
        outs.pop_front();
        b->deleteLater();
    }
    while ( labels.size() > 0 )
    {
        QLabel * l = labels.front();
        outs.pop_front();
        l->deleteLater();
    }
    ins.clear();
    outs.clear();
    labels.clear();
    outsV.clear();
}

void ValveTst::setInputs( int boardInd, quint32 value )
{
    emit sigSetInputs( boardInd, value );
}

void ValveTst::setOutputs( int boardInd, quint32 value )
{
    emit sigSetOutputs( boardInd, value );
}

quint32 ValveTst::outputs( int boardInd )
{
    QMutexLocker lock( &mutex );
    return outsV[ boardInd ];
}

void ValveTst::slotSetInputs( int boardInd, quint32 value )
{
    for ( int i=0; i<16; i++ )
    {
        int ind = 16 * boardInd + (15 - i);
        Led * led = ins[ind];
        led->setChecked( value & (1 <<  i) );
    }
}

void ValveTst::slotSetOutputs( int boardInd, quint32 value )
{
    quint32 res = 0;
    for ( int i=0; i<32; i++ )
    {
        int ind = boardInd * 32 + ( 31 - i );
        QSwitch * b = outs[ind];
        b->setValue( ( (value & (1 << i) ) > 0 ) );
    }
    QMutexLocker lock( &mutex );
    outsV[ boardInd ] = value;
}

void ValveTst::slotOutChanged()
{
    for ( int j=0; j<outsV.size(); j++ )
    {
        quint32 res = 0;
        for ( int i=0; i<32; i++ )
        {
            int ind = j * 32 + ( 31 - i );
            QSwitch * b = outs[ind];
            if ( b->value() )
                res += (1 << i);
        }
        QMutexLocker lock( &mutex );
        outsV[j] = res;
    }
}

void ValveTst::slotApply()
{
}




