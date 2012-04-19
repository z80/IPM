
#include "main_wnd.h"
#include "ui_main_wnd.h"
#include "log_wnd.h"
#include "js-binder.h"

class ResInit
{
public:
    ResInit()
    {
        Q_INIT_RESOURCE( images );
    }

    ~ResInit()
    {
    }

    static ResInit & init()
    {
        static ResInit i;
        return i;
    }
};

class MainWnd::PD
{
public:
    Ui_MainWnd ui;
    LogWnd      * logWnd;
    QDockWidget * logDock;

    QTimer * timer;

    JsBinder * binder;
};

MainWnd::MainWnd( QWidget * parent )
: QMainWindow( parent )
{
    ResInit::init();

    pd = new PD();
    pd->ui.setupUi( this );

    pd->logDock = new QDockWidget( "Log", this );
    connect( pd->ui.log,  SIGNAL(toggled(bool)),           pd->logDock, SLOT(setVisible(bool)) );
    connect( pd->logDock, SIGNAL(visibilityChanged(bool)), pd->ui.log,  SLOT(setChecked(bool)) );
    pd->logDock->setAllowedAreas( Qt::LeftDockWidgetArea | 
                                  Qt::RightDockWidgetArea );
    pd->logWnd = new LogWnd( this );
    pd->logDock->setWidget( pd->logWnd );
    addDockWidget(Qt::RightDockWidgetArea, pd->logDock );
    pd->logDock->setVisible( false );

    pd->timer = new QTimer( this );
    pd->timer->setInterval( 50 );
    connect( pd->timer, SIGNAL(timeout()), this, SIGNAL(timeout()) );

    pd->binder = new JsBinder( this );
    pd->binder->registerMain( this );
    pd->binder->run( ":/js/main.js" );
}

MainWnd::~MainWnd()
{
    delete pd;
}

void MainWnd::log( const QString & stri )
{
    pd->logWnd->log( stri );
}

void MainWnd::clear()
{
    pd->logWnd->clear();
}

void MainWnd::setTimerInterval( int ms )
{
    pd->timer->setInterval( ms );
}

void MainWnd::setTimerEnabled( bool en )
{
    if ( en )
        pd->timer->start();
    else
        pd->timer->stop();
}

bool MainWnd::isTimerEnabled() const
{
    return pd->timer->isActive();
}




