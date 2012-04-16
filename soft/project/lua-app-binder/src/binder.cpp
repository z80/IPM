
#include "lua.hpp"
#include "binder.h"

class Binder::PD
{
public:
    PD() {}
    ~PD() {}

    lua_State * L;
};

Binder::Binder()
{
    pd = new PD();
    pd->L = luaL_newstate();
    luaL_openlibs( pd->L );
}

Binder::~Binder()
{
    lua_close( pd->L );
    delete pd;
}

lua_State * Binder::state()
{
    return pd->L;
}

bool Binder::execFile( const std::string & fileName, std::string & errorMessage )
{
    // Запуск файла с копированием или без копирования.
}

bool Binder::execString( const std::string & string, std::string & errorMessage )
{
}




