
#ifndef __MAIN_WND_H_
#define __MAIN_WND_H_

#include "ui_main_wnd.h"
#include "mcu_ctrl.h"
#include <QtGui>

class MainWnd: public QWidget
{
    Q_OBJECT
public:
    MainWnd( QWidget * parent = 0 );
    ~MainWnd();

public slots:
    void slotOpen();
    void slotTimeout();
public:
    Ui_MainWnd ui;
    QTimer * m_timer;
    McuCtrl mcu;
};

#endif




