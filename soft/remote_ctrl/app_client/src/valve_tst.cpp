
#include "valve_tst.h"
#include "led.h"

ValveTst::ValveTst( QWidget * parent )
: QWidget( parent )
{
    lt = new QGridLayout( this );
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
            lt->addWidget( led, i*2, j );
            ins << led;
        }
        for ( int j=0; j<32; j++ )
        {
            QPushButton * b = new QPushButton( this );
            b->setMaximumSize( QSize( 32, 32 ) );
            b->setMinimumSize( QSize( 32, 32 ) );
            b->setText( QString( "%1" ).arg( j ) );
            b->setCheckable( true );
            lt->addWidget( b, 2*i+1, j );
            outs << b;
        }
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
        QPushButton * b = outs.front();
        outs.pop_front();
        b->deleteLater();
    }
}

void ValveTst::setInputs( int boardInd, quint32 value )
{
}

void ValveTst::outputs( int boardInd, quint32 value )
{
}

void ValveTst::slotApply()
{
}

void ValveTst::slotOutChanged()
{
}




