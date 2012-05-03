
#include <IceE/IceE.h>
#include "thread_ice.h"

int main(int argc, char* argv[])
{
    IceUtil::ThreadPtr t = new ThreadIce( "", "host.cfg" );
    IceUtil::ThreadControl tc = t->start();
    tc.join();

    return 0;
}






