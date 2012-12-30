
#ifndef __MAIN_WND_H_
#define __MAIN_WND_H_

#include <QtGui>
#include "peer_qxmpp.h"
#include "host_qxmpp.h"
#include "ui_main_wnd.h"

class ValveTst;

class MainWnd: public QMainWindow
{
    Q_OBJECT
public:
    MainWnd( QWidget * parent = 0 );
    ~MainWnd();

    bool eventFilter( QObject * o, QEvent * e );
signals:
    void sigLog( const QString & );
    void sigImageAccepted();
private slots:
    void slotLog( const QString & );
    void slotImageAccepted();
public:
    int print( lua_State * L );
    int joy( lua_State * L );
    ValveTst * valveTst();
private:
    void init( lua_State * L );
    QIODevice * inFileHandler( const std::string & fileName );
    void accFileHandler( const std::string & fileName, QIODevice * file );
    void log( const std::string & stri );
    void updatePixmap( const QImage & img = QImage() );
    void sceneResizeEvent( QResizeEvent * e );

    Ui_MainWnd  ui;
    PeerQxmpp * m_peer;
    HostQxmpp * m_host;
    QTime       m_time;
    QStringList m_logList;

    QGraphicsScene      * m_scene;
    QGraphicsPixmapItem * m_image;
    QPixmap               m_pixmap;

    ValveTst             * m_valveTst;

    static const std::string CLIENT_CONFIG_FILE;
    static const std::string SERVER_CONFIG_FILE;
    static const int         LOG_MAX;

    QImage m_img;

    QMutex mutex;
    QPointF m_joy1, m_joy2, m_joy3, m_joy4;
public slots:
    void slotSend( const QString & stri );
    void slotImage();
    void slotConnect();
    void slotExec();
    void slotSendFile();
    void slotHelp();
    void slotJoyChanged( QPointF v, bool mouseDown );
};



#endif



