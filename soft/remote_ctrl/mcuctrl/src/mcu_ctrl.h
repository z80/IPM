
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

    bool i2cSetAddr( int addr );
    bool i2cSetBuf( int start, unsigned char * data, int cnt );
    bool i2cIo( int txCnt, int rxCnt );
    bool i2cStatus( int & status );
    bool i2cBuffer( int cnt, unsigned char * data );
};


#endif





