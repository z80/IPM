
#ifndef __JOY_CTRL_H_
#define __JOY_CTRL_H_

class JoyCtrl
{
public:
    JoyCtrl();
    ~JoyCtrl();

    bool open();
    bool isOpen();
    void close();

    bool query();

public:
    class PD;
    PD * pd;
};



#endif


