
#ifndef __JOY_CTRL_TOP_H_
#define __JOY_CTRL_TOP_H_

#include "joy_ctrl.h"

class JoyCtrlTop: public JoyCtrl
{
public:
    JoyCtrlTop();
    ~JoyCtrlTop();

    bool queryState();
    int  joy( int index );
    bool nullX( int index );
    bool nullY( int index );
    bool stopBtn();

private:
    class PD;
    PD * pd;
};





#endif





