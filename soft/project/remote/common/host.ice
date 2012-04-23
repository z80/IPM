
#ifndef __HOST_ICE_
#define __HOST_ICE_

#include <IceE/Identity.ice>
#include "types.ice"
#include "client.ice"

module Host
{
    class Pneumo
    {
        string state();
    };
    class TurnMoto
    {
        string state();
    };
    class Manipulator
    {
        string state();
    };
    class Actuator
    {
        string state();
    };

    class CHost
    {
        string version();
        Pneumo      * pneumo();
        TurnMoto    * turnMotor();
        Manipulator * manipulator();
        Actuator    * actuator();
    };

};



#endif


