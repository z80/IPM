
#include "lua.hpp"

class Binder::PD
{
public:
    PD() {}
    ~PD() {}

    lua_State * L;
};

    Binder( EventHandler * handler = 0 );
    ~Binder();
    // For continous script execution.
    virtual void handler() = 0;
    // For print() function implementation.
    virtual void echo( const std::string & stri ) = 0;
    
    lua_State * state();
    //void enterCritical();
    //void leaveCritical();

    bool execFile( const std::string & fileName, std::string & errorMessage );
    bool execString( const std::string & string, std::string & errorMessage );
    
    PD * pd;




