
#include <sstream>
#include "main_wnd.h"
#include "valve_tst.h"
#include "lua.hpp"
#include "boost/bind.hpp"
#include "boost/bind/placeholders.hpp"
#include "luajoyctrl.h"

const std::string MainWnd::CLIENT_CONFIG_FILE = "client.ini";
const std::string MainWnd::SERVER_CONFIG_FILE = "server.ini";
const int         MainWnd::LOG_MAX     = 256;

MainWnd::MainWnd( QWidget * parent )
: QMainWindow( parent )
{
    ui.setupUi( this );
    connect( this,       SIGNAL(sigLog(const QString &)),        this, SLOT(slotLog(const QString &)),  Qt::QueuedConnection );
    connect( ui.console, SIGNAL(line_validate(const QString &)), this, SLOT(slotSend(const QString &)), Qt::QueuedConnection );

    connect( this, SIGNAL(sigImageAccepted()), this, SLOT(slotImageAccepted()), Qt::QueuedConnection );

    QObject::connect( ui.joy1, SIGNAL(valueChanged(QPointF, bool)),
                      this,    SLOT(slotJoyChanged(QPointF, bool)) );
    QObject::connect( ui.joy2, SIGNAL(valueChanged(QPointF, bool)),
                      this,    SLOT(slotJoyChanged(QPointF, bool)) );
    QObject::connect( ui.joy3, SIGNAL(valueChanged(QPointF, bool)),
                      this,    SLOT(slotJoyChanged(QPointF, bool)) );
    QObject::connect( ui.joy4, SIGNAL(valueChanged(QPointF, bool)),
                      this,    SLOT(slotJoyChanged(QPointF, bool)) );


    ui.joy1->setBackgroundColor1( QColor( qRgb( 0xff, 0xcc, 0x19 ) ) );
    ui.joy1->setBackgroundColor2( QColor( qRgb( 0xac, 0x86, 0x00 ) ) );
    ui.joy1->setEffectColor( QColor( qRgb( 0x39, 0xba, 0x00 ) ) );

    ui.joy2->setBackgroundColor1( QColor( qRgb( 0xff, 0xcc, 0x19 ) ) );
    ui.joy2->setBackgroundColor2( QColor( qRgb( 0xac, 0x86, 0x00 ) ) );
    ui.joy2->setEffectColor( QColor( qRgb( 0x39, 0xba, 0x00 ) ) );

    m_scene = new QGraphicsScene( ui.view );
    m_scene->setBackgroundBrush( QBrush( Qt::gray ) );
    ui.view->setScene( m_scene );
    ui.view->installEventFilter( this );

    m_image = new QGraphicsPixmapItem( 0, m_scene );
    m_image->setPos( 0.0, 0.0 );

    m_valveTst = new ValveTst( 0 );

    connect( ui.image,   SIGNAL(triggered()), this,       SLOT(slotImage()) );
    connect( ui.connect, SIGNAL(triggered()), this,       SLOT(slotConnect()) );
    connect( ui.exec,    SIGNAL(triggered()), this,       SLOT(slotExec()) );
    connect( ui.send,    SIGNAL(triggered()), this,       SLOT(slotSendFile()) );
    connect( ui.help,    SIGNAL(triggered()), this,       SLOT(slotHelp()) );
    connect( ui.valve,   SIGNAL(triggered()), m_valveTst, SLOT(show()) );

    m_peer = new PeerQxmpp( CLIENT_CONFIG_FILE, boost::bind( &MainWnd::init, this, _1 ) );
    m_peer->setInFileHandler( boost::bind<QIODevice *>( &MainWnd::inFileHandler, this, _1 ) );
    m_peer->setAccFileHandler( boost::bind( &MainWnd::accFileHandler, this, _1, _2 ) );
}

MainWnd::~MainWnd()
{
    m_scene->deleteLater();
    m_valveTst->deleteLater();
    delete m_image;
    delete m_peer;
}

bool MainWnd::eventFilter( QObject * o, QEvent * e )
{
    if ( e->type() == QEvent::Resize )
    {
        QResizeEvent * re = dynamic_cast<QResizeEvent *>( e );
        if ( re )
            sceneResizeEvent( re );
    }
    return false;
}

void MainWnd::slotLog( const QString & stri )
{
    ui.console->print( stri );
    ui.console->print( "\n" );
}

void MainWnd::slotImageAccepted()
{
    updatePixmap( m_img );
}

static int print( lua_State * L )
{
    lua_pushstring( L, "MainWnd" );
    lua_gettable( L, LUA_REGISTRYINDEX );
    MainWnd * mw = reinterpret_cast<MainWnd *>( const_cast<void *>( lua_topointer( L, -1 ) ) );
    lua_pop( L, 1 );
    return mw->print( L );
}

static int joy( lua_State * L )
{
    lua_pushstring( L, "MainWnd" );
    lua_gettable( L, LUA_REGISTRYINDEX );
    MainWnd * mw = reinterpret_cast<MainWnd *>( const_cast<void *>( lua_topointer( L, -1 ) ) );
    lua_pop( L, 1 );
    return mw->joy( L );
}

static int valveSetInputs( lua_State * L )
{
    lua_pushstring( L, "MainWnd" );
    lua_gettable( L, LUA_REGISTRYINDEX );
    MainWnd * mw = reinterpret_cast<MainWnd *>( const_cast<void *>( lua_topointer( L, -1 ) ) );
    lua_pop( L, 1 );
    int boardInd  = static_cast<int>( lua_tonumber( L, 1 ) );
    quint32 value = static_cast<quint32>( lua_tonumber( L, 2 ) );
    mw->valveTst()->setInputs( boardInd, value );
    return 0;
}

static int valveSetOutputs( lua_State * L )
{
    lua_pushstring( L, "MainWnd" );
    lua_gettable( L, LUA_REGISTRYINDEX );
    MainWnd * mw = reinterpret_cast<MainWnd *>( const_cast<void *>( lua_topointer( L, -1 ) ) );
    lua_pop( L, 1 );
    int boardInd  = static_cast<int>( lua_tonumber( L, 1 ) );
    quint32 value = static_cast<quint32>( lua_tonumber( L, 2 ) );
    mw->valveTst()->setOutputs( boardInd, value );
    return 0;
}

static int valveOutputs( lua_State * L )
{
    lua_pushstring( L, "MainWnd" );
    lua_gettable( L, LUA_REGISTRYINDEX );
    MainWnd * mw = reinterpret_cast<MainWnd *>( const_cast<void *>( lua_topointer( L, -1 ) ) );
    lua_pop( L, 1 );
    int boardInd  = static_cast<int>( lua_tonumber( L, 1 ) );
    quint32 value = mw->valveTst()->outputs( boardInd );
    lua_pushnumber( L, static_cast<lua_Number>( value ) );
    return 1;
}

void MainWnd::init( lua_State * L )
{
    lua_pushstring( L, "MainWnd" );
    lua_pushlightuserdata( L, reinterpret_cast<void *>( this ) );
    lua_settable( L, LUA_REGISTRYINDEX );

    lua_pushstring( L, "print" );
    lua_pushcfunction( L, ::print );
    lua_settable( L, LUA_GLOBALSINDEX );

    lua_pushstring( L, "joy" );
    lua_pushcfunction( L, ::joy );
    lua_settable( L, LUA_GLOBALSINDEX );

    lua_pushstring( L, "valveSetInputs" );
    lua_pushcfunction( L, ::valveSetInputs );
    lua_settable( L, LUA_GLOBALSINDEX );

    lua_pushstring( L, "valveSetOutputs" );
    lua_pushcfunction( L, ::valveSetOutputs );
    lua_settable( L, LUA_GLOBALSINDEX );

    lua_pushstring( L, "valveOutputs" );
    lua_pushcfunction( L, ::valveOutputs );
    lua_settable( L, LUA_GLOBALSINDEX );

    // Joysticks board io.
    luaopen_luajoyctrl( L );

    // Execute file.
    luaL_dofile( L, "./client.lua" );
}

QIODevice * MainWnd::inFileHandler( const std::string & fileName )
{
    QString fn = QString::fromStdString( fileName );
    if ( fn.toLower().right( 4 ) == ".png" )
    {
        QBuffer * buf = new QBuffer();
        buf->open( QIODevice::WriteOnly );
        return buf;
    }
    return 0;
}

void MainWnd::accFileHandler( const std::string & fileName, QIODevice * file )
{
    if ( file->isOpen() )
        file->close();
    if ( !file->open( QIODevice::ReadOnly ) )
        return;
    if ( m_img.load( file, "PNG" ) )
        emit sigImageAccepted();
}

int MainWnd::print( lua_State * L )
{
    int top = lua_gettop( L );
    for ( int i=1; i<=top; i++ )
    {
        std::string stri = lua_tostring( L, i );
        log( stri );
    }
    lua_settop( L, 0 );
    return 0;
}

int MainWnd::joy( lua_State * L )
{
    int top = lua_gettop( L );
    int index;
    if ( top > 0 )
        index = static_cast<int>( lua_tonumber( L, 1 ) );
    else
        index = 1;
    QPointF at;
    {
        QMutexLocker lock( &mutex );
        switch ( index )
        {
        case 2:
            at = m_joy2;
            break;
        case 3:
            at = m_joy3;
            break;
        case 4:
            at = m_joy4;
            break;
        default:
            at = m_joy1;
            break;
        }
    }
    lua_pushnumber( L, static_cast<lua_Number>( at.x() ) );
    lua_pushnumber( L, static_cast<lua_Number>( at.y() ) );
    //lua_settop( L, 0 );
    return 2;
}

ValveTst * MainWnd::valveTst()
{
    return m_valveTst;
}

void MainWnd::log( const std::string & stri )
{
    QString qstri = QString::fromStdString( stri );
    emit sigLog( qstri );
}

void MainWnd::slotSend( const QString & stri )
{
    std::string sstri = stri.toStdString();
    m_peer->send( sstri );
}

void MainWnd::slotImage()
{
    const std::string cmd = "image()";
    m_peer->send( cmd );
}

void MainWnd::slotConnect()
{
    m_peer->PeerQxmpp::connect();
}

void MainWnd::slotExec()
{
    QString stri =
        QFileDialog::getOpenFileName( this, tr( "Open script file" ),
                                                "",
                                            tr("Lua script (*.lua)") );
    if ( stri.length() > 0 )
    {
        std::ostringstream out;
        out << "local ch, err = loadfile( \"";
        out << stri.toStdString();
        out << "\" )\n";
        out << "if ( not ch ) then\n";
        out << "    print( err )\n";
        out << "else\n";
        out << "    ch()\n";
        out << "end";
        m_peer->invokeCmd( out.str() );
    }
}

void MainWnd::slotSendFile()
{
    QString stri =
        QFileDialog::getOpenFileName( this, tr( "Open script file" ),
                                                "",
                                            tr("Lua script (*.lua)") );
    if ( stri.length() > 0 )
    {
        QFile * f = new QFile( stri );
        if ( !f->open( QIODevice::ReadOnly ) )
        {
            QMessageBox::critical( this, "Error", "Can\'t open file for reading" );
            return;
        }
        QFileInfo fi( stri );
        QString name = fi.fileName();
        m_peer->sendFile( name.toStdString(), f );
    }
}

void MainWnd::updatePixmap( const QImage & img )
{
    if ( !img.isNull() )
        m_pixmap = QPixmap::fromImage( img );
    if ( m_pixmap.isNull() )
        return;

    QSizeF imgSz = m_pixmap.size();
    QSizeF wndSz = ui.view->size();

    qreal sc;
    qreal x, y;
    if ( ( imgSz.width() * wndSz.height() ) > ( imgSz.height() * wndSz.width() ) )
    {
        sc = wndSz.width() / imgSz.width();
        x = 0.0;
        y = ( static_cast<qreal>( wndSz.height() ) -
              static_cast<qreal>( imgSz.height() ) * sc ) * 0.5;
    }
    else
    {
        sc = wndSz.height() / imgSz.height();
        x = ( static_cast<qreal>( wndSz.width() ) -
              static_cast<qreal>( imgSz.width() ) * sc ) * 0.5;
        y = 0.0;
    }
    m_scene->setSceneRect( QRectF( 0.0, 0.0, wndSz.width(), wndSz.height() ) );
    m_image->setPixmap( m_pixmap );

    QTransform scale;
    scale.scale( sc, sc );

    QTransform tran;
    tran.translate( x, y );

    tran = scale * tran;
    m_image->setTransform( tran );
}

void MainWnd::sceneResizeEvent( QResizeEvent * e )
{
    QSizeF sz = ui.view->size();
    ui.view->setSceneRect( 0.0, 0.0, sz.width() - 10, sz.height() - 10 );
    updatePixmap();
}

void MainWnd::slotHelp()
{
    QDesktopServices::openUrl( QUrl( "help\\index.html" ) );
}

void MainWnd::slotJoyChanged( QPointF v, bool mouseDown )
{
    AnalogPad * ap = qobject_cast<AnalogPad *>( sender() );
    if ( ap == ui.joy1 )
    {
        QMutexLocker lock( &mutex );
        m_joy1 = v * 200.0;
    }
    else if ( ap == ui.joy2 )
    {
        QMutexLocker lock( &mutex );
        m_joy2 = v * 200.0;
    }
    else if ( ap == ui.joy3 )
    {
        QMutexLocker lock( &mutex );
        m_joy3 = v * 200.0;
    }
    else
    {
        QMutexLocker lock( &mutex );
        m_joy4 = v * 200.0;
    }

}





