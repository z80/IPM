
#include "main_wnd.h"

MainWnd::MainWnd( QWidget * parent )
    : QWidget( parent )
{
    ui.setupUi( this );
    connect( ui.open, SIGNAL(clicked()), this, SLOT(slotOpen()) );
    m_timer = new QTimer( this );
    m_timer->setInterval( 100 );
    m_timer->start();
    connect( m_timer, SIGNAL(timeout()), this, SLOT(slotTimeout()) );
}

MainWnd::~MainWnd()
{

}

void MainWnd::slotOpen()
{
    if ( ui.open->isChecked() )
    {
        bool res = mcu.open();
        if ( !res )
            ui.open->setChecked( false );
    }
    else
        mcu.close();
}


void MainWnd::slotTimeout()
{
    if ( !mcu.isOpen() )
    {
        setWindowTitle( "Device is closed!" );
        return;
    }
    const int cnt = 2;
    unsigned long v[cnt];
    bool res = mcu.inputs( v, cnt );
    if ( !res )
    {
        setWindowTitle( "I/O error!" );
        return;
    }
    QString label = "";
    for ( int i=0; i<cnt; i++ )
    {
        int v1, v2, v3, v4;
        v1 = (v[i] >> 12) & 0b00001111;
        v2 = (v[i] >> 8)  & 0b00001111;
        v3 = (v[i] >> 4)  & 0b00001111;
        v4 = v[i]         & 0b00001111;
        QString stri = QString( "%1 %2 %3 %4\n%5\n" ).arg( v1, 4, 2, QChar( '0' ) ).arg( v2, 4, 2, QChar( '0' ) )
                                                     .arg( v3, 4, 2, QChar( '0' ) ).arg( v4, 4, 2, QChar( '0' ) )
                                                     .arg( v[i], 8, 16, QChar( '0' ) );
        label = QString( "%1%2" ).arg( label ).arg( stri );
    }
    ui.state->setText( label );
    setWindowTitle( "OK!" );
}



