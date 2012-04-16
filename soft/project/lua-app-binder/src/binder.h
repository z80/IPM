
#ifndef __BINDER_H_
#define __BINDER_H_

#include <string>
#include <list>
//#include "boost::any.hpp"

struct lua_State;

class Binder
{
public:
    /*class Object
    {
    };

    class ObjectFactory
    {
    public:
        virtual const std::string & typename() = 0;
        virtual Object * create() = 0;
    }*/


    Binder();
    virtual ~Binder();
    // For continous script execution.
    virtual void handler() = 0;
    // For print() function implementation.
    virtual void echo( const std::string & stri ) = 0;
    // To access resource files. If file doesn't exist it should get it from resource.
    virtual bool resourceFile( const std::string & fileName, std::basic_string<char> & content ) = 0;
    
    lua_State * state();
    //void enterCritical();
    //void leaveCritical();
    
    bool execFile( const std::string & fileName, std::string & errorMessage );
    bool execString( const std::string & string, std::string & errorMessage );
    
private:
    class PD;
    PD * pd;
};

#endif

