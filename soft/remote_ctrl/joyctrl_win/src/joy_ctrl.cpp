
#include "joy_ctrl.h"
#include <windows.h>
#include "ftd2xx.h"


class JoyCtrl::PD
{
public:
    PD() {}
    ~PD() {}

    FT_STATUS  res;
    FT_HANDLE  handle;
    bool       opened;
};

JoyCtrl::JoyCtrl()
{
    pd = new PD();
}

JoyCtrl::~JoyCtrl()
{
    delete pd;
}

bool JoyCtrl::open()
{
    DWORD cnt = 0;
    pd->opened = false;
    pd->res = FT_ListDevices( &cnt, 0, FT_LIST_NUMBER_ONLY );
    if ( pd->res == FT_OK )
    {
        for ( DWORD i=0; i<cnt; i++ )
        {
            char desc[640];
            pd->res = FT_ListDevices( (PVOID)i, desc, FT_LIST_BY_INDEX | FT_OPEN_BY_DESCRIPTION );
            if ( pd->res != FT_OK )
                continue;
            pd->res = FT_Open( i, &pd->handle );
            pd->opened = (pd->res == FT_OK);
            if ( pd->opened )
            {
                pd->res = FT_SetTimeouts( pd->handle, 500, 500 );
                if ( pd->res != FT_OK )
                    return false;
                pd->res = FT_SetBaudRate( pd->handle, FT_BAUD_38400 );
                if ( pd->res != FT_OK )
                    return false;
                pd->res = FT_SetDataCharacteristics( pd->handle, FT_BITS_8, FT_STOP_BITS_1, FT_PARITY_NONE );
                if ( pd->res != FT_OK )
                    return false;
                pd->res = FT_SetFlowControl( pd->handle, FT_FLOW_NONE, 0, 0 );
                if ( pd->res != FT_OK )
                    return false;
                pd->res = FT_SetRts( pd->handle );
                if ( pd->res != FT_OK )
                    return false;
                return true;
            }
        }
    }
    return false;
}

bool JoyCtrl::isOpen()
{
    return pd->opened;
}


void JoyCtrl::close()
{
    pd->res = FT_Close( pd->handle );
    pd->opened = false;
}

bool JoyCtrl::query( unsigned char * result, int & sz )
{
    const int SZ = 20;
    unsigned char buffer[SZ];
    DWORD written = 0;
    pd->res = FT_Write( pd->handle, reinterpret_cast<LPVOID>( buffer ), 1, &written );
    if ( written < 1 )
        return false;
    
    int tries = 500;
    DWORD bytes = 0;
    do
    {
        pd->res = FT_GetQueueStatus( pd->handle, &bytes );
        if ( pd->res != FT_OK )
            return false;
        if ( bytes < SZ )
            Sleep( 1 );
        tries--;
        if ( tries <= 0 )
            return false;

    } while ( bytes < SZ );
    pd->res = FT_Read( pd->handle, reinterpret_cast<LPVOID>( buffer ), static_cast<DWORD>( SZ ), &bytes );
    if ( pd->res != FT_OK )
        return false;
    memcpy( result, buffer, bytes );
    sz = bytes;
    if ( bytes < SZ )
        return false;
    return true;
}







