

#include <QtGui>
#include "main_wnd.h"

int main( int argc, char * argv[] )
{
    //QApplication::setColorSpec( QApplication::CustomColor );
    QApplication a( argc, argv );

    MainWnd * c = new MainWnd();
    c->show();

    int ret = a.exec();

    return ret;
}









