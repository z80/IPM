
extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}
#include "binder.h"
#include <sstream>

static void lineHook( lua_State * L, lua_Debug * ar );
// Overwriteble functions in Lua.
static int  print( lua_State * L );
static int  loadfile( lua_State * L );

class Binder::PD
{
public:
    PD() {}
    ~PD() {}

    lua_State * L;
    bool trace, 
         copyFiles, 
         running;
    static const std::string BINDER;
    static const std::string LOADFILE;
    static void echoDebug( Binder * b, lua_Debug * ar );
    static void placeBinder( Binder * b, lua_State * L );
    static void printOverwrite( Binder * b, lua_State * L );
    static void loadfileOverwrite( Binder * b, lua_State * L );
    static void pushBinder( lua_State * L );
    static void pushLoadfile( lua_State * L );
};

const std::string Binder::PD::BINDER   = "binder";
const std::string Binder::PD::LOADFILE = "binder_loadfile";

void Binder::PD::echoDebug( Binder * b, lua_Debug * ar )
{
    b->echo( ar->name );
    b->echo( ar->namewhat );
    b->echo( ar->what );
    //b->echo( ar->source );
    b->echo( ar->short_src );
    std::ostringstream os;
    os << ar->currentline;
    b->echo( os.str() );
}

void Binder::PD::placeBinder( Binder * b, lua_State * L )
{
    int t = lua_gettop( L );
    lua_pushvalue( L, LUA_REGISTRYINDEX );
    lua_pushstring( L, PD::BINDER.data() );
    lua_pushlightuserdata( L, reinterpret_cast<void *>( b ) );
    lua_settable( L, -3 );
    lua_settop( L, t );
}

void Binder::PD::printOverwrite( Binder * b, lua_State * L )
{
    int t = lua_gettop( L );
    lua_pushstring( L, "print" );
    lua_pushcfunction( L, print );
    lua_settable( L, LUA_GLOBALSINDEX );
    lua_settop( L, t );
}

void Binder::PD::loadfileOverwrite( Binder * b, lua_State * L )
{
    int t = lua_gettop( L );
    lua_pushstring( L, "loadfile" );
    lua_gettable( L, LUA_GLOBALSINDEX );
    lua_pushstring( L, LOADFILE.data() );
    lua_pushvalue( L, -2 );
    lua_settable( L, LUA_REGISTRYINDEX );
    lua_pushstring( L, "loadfile" );
    lua_pushcfunction( L, loadfile );
    lua_settable( L, LUA_GLOBALSINDEX );
    lua_settop( L, t );
}

void Binder::PD::pushBinder( lua_State * L )
{
    lua_pushstring( L, BINDER.data() );
    lua_gettable( L, LUA_REGISTRYINDEX );
}

void Binder::PD::pushLoadfile( lua_State * L )
{
    lua_pushstring( L, LOADFILE.data() );
    lua_gettable( L, LUA_REGISTRYINDEX );
}

Binder::Binder()
{
    pd = new PD();
    pd->trace     = false;
    pd->copyFiles = true;
    pd->running   = false;
    pd->L = luaL_newstate();
    luaL_openlibs( pd->L );
    lua_sethook( pd->L, lineHook, LUA_HOOKLINE, 0 );
    PD::placeBinder( this, pd->L );
    PD::printOverwrite( this, pd->L );
    PD::loadfileOverwrite( this, pd->L );
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

bool Binder::execFile( const std::string & fileName )
{
    // Запуск файла с копированием или без копирования.
    FILE * fp = fopen( fileName.data(), "r" );
    if ( !fp )
    {
        std::basic_string<char> content;
        bool exists = resourceFile( fileName, content );
        if ( !exists )
        {
            std::ostringstream os;
            os << "ERROR: no such file \'" << fileName << "\'";
            echo( os.str() );
        }
        if ( pd->copyFiles )
        {
            fp = fopen( fileName.data(), "w" );
            if ( fp )
            {
                fwrite( content.data(), 1, content.size(), fp );
                fclose( fp );
            }
            else
            {
                std::ostringstream os;
                os << "ERROR: failed to copy file \'" << fileName << "\'";
                echo( os.str() );
            }
            // Execution from file.
            PD::pushLoadfile( L );
            lua_pushstring( L, fileName.data() );
            int err = lua_pcall( L, 1, 2, 0 );            
            bool res = (err == 0);
            return res;
        }
        else
        {
            // Execution from string.
            bool res = execString( content );
            return res;
        }

    }
    else
        fclose( fp );
    return false;
}

bool Binder::execString( const std::string & stri )
{
    lua_pushstring( L, "loadstring" );
    lua_gettable( L, LUA_GLOBALSINDEX );
    lua_pushstring( L, stri.data() );
    int err = lua_pcall( L, 1, 2, 0 );
    bool res = (err == 0);
    return res;
}

void setCopyResourceFiles( bool en )
{
    pd->copyFiles = en;
}

void Binder::setTrace( bool en )
{
    pd->trace = en;
}

bool Binder::isTrace() const
{
    return pd->trace;
}

bool Binder::isRun() const
{
    return pd->running;
}

bool Binder::stopExec()
{
    return true;
}

bool Binder::breakExec()
{
    if ( pd->running )
    {
        int n = lua_gettop( L );
        lua_Debug ar;
        lua_getstack( L, 0, &ar );
        lua_getinfo( pd->L, "lS" );
        lua_settop( L, n );

        std::ostringstream os;
        os << "Execution interrupted at " << ar.short_src << ", line number" << ar.currentline;
        lua_pushstring( pd->L, os.str().data() );
        lua_error( L );

        return true;
    }
    return false;
}

bool Binder::contExec()
{
    return true;
}

bool Binder::stepOver()
{
    return false;
}

bool Binder::stepInto()
{
    return false;
}

bool Binder::stepOut()
{
    return false;
}

bool Binder::eval( const std::string & stri )
{
    return false;
}

static void lineHook( lua_State * L, lua_Debug * ar )
{
    if ( pd->trace )
        PD::echoDebug( L, ar );
    int n = lua_gettop( L );
    PD::pushBinder( L );
    Binder * b = reinterpret_cast<Binder *>( lua_topointer( L, -1 ) );
    pd->running = true;
    b->handler();
    pd->running = false;
    lua_settop( L, n );
}

static int print( lua_State * L )
{
    int n = lua_gettop( L );
    PD::pushBinder( L );
    Binder * b = reinterpret_cast<Binder *>( lua_topointer( L, -1 ) );
    lua_pushstring( L, "tostring" );
    lua_gettable( L, LUA_GLOBALSINDEX );
    for ( int i=1; i<=n; i++ )
    {
        lua_pushvalue( L, -1 );
        lua_pushvalue( L, i );
        int res = lua_pcall( L, 1, 1, 0 );
        std::string stri;
        stri = lua_tostring( L, -1 );
        lua_pop( L, 1 );
        b->echo( stri );
    }
    lua_settop( L, n );
    return 0;
}

static int loadfile( lua_State * L )
{
    int n = lua_gettop( L );
    if ( n < 1 )
    {
        lua_pushnil( L );
        lua_pushstring( L, "ERROR: file name expected" );
    }
    // If file exists or not.
    std::string fileName = lua_tostring( L, 1 );
    FILE * fp = fopen( fileName.data(), "r" );
    if ( fp )
    {
        fclose( fp );
        PD::pushLoadfile( L );
        lua_pushvalue( L, 1 );
        int res = lua_pcall( L, 1, 2, 0 );
        int nres = lua_gettop( L );
        nres -= n;
        return nres;
    }
    PD::pushBinder( L );
    Binder * b = reinterpret_cast<Binder *>( lua_topointer( L, -1 ) );
    
    std::basic_string<char> content;
    bool res = b->resourceFile( fileName, content );
    if ( !res )
    {
        lua_pushnil( L );
        std::ostringstream os;
        os << "ERROR: file not found \'" << fileName << "\'";
        lua_pushstring( L, os.str().data() );
    }
    lua_pushstring( L, "loadstring" );
    lua_gettable( L, LUA_GLOBALSINDEX );
    lua_pushstring( L, content.data() );
    int err = lua_pcall( L, 1, 2, 0 );
    int nres = lua_gettop( L );
    nres -= n;
    return nres;
}


