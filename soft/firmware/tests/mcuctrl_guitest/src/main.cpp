
#include "mcu_ctrl.h"

#include "main_wnd.h"

int main( int argc, char * argv[] )
{
    QApplication app( argc, argv );
    MainWnd * mw = new MainWnd();
    mw->show();
    int res = app.exec();

    return res;
}

