
#ifndef __MCU_CTRL_H_
#define __MCU_CTRL_H_

#include "usb_io.h"

class McuCtrl: public UsbIo
{
public:
    McuCtrl();
    ~McuCtrl();

    bool inputs( unsigned long * data, int len = 2 );
    bool setOutputs( unsigned long * data, int len = 2 );
};


#endif





