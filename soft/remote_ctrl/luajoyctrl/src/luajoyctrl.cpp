
#include "luajoyctrl.h"
#include "joy_ctrl.h"

static const char META[] = "LUA_JOYCTRL_META";
static const char LIB_NAME[] = "luajoyctrl";

static int create( lua_State * L )
{
    int cnt = lua_gettop( L );
    JoyCtrl * io = new JoyCtrl();
    JoyCtrl * * p = reinterpret_cast< JoyCtrl * * >( lua_newuserdata( L, sizeof( JoyCtrl * ) ) );
    *p = dynamic_cast<JoyCtrl *>( io );
    luaL_getmetatable( L, META );
    lua_setmetatable( L, -2 );
    return 1;
}

static int gc( lua_State * L )
{
    JoyCtrl * io = *reinterpret_cast<JoyCtrl * *>( lua_touserdata( L, 1 ) );
    if ( io )
        delete io;
    return 0;
}

static int self( lua_State * L )
{
    JoyCtrl * io = *reinterpret_cast<JoyCtrl * *>( lua_touserdata( L, 1 ) );
    lua_pushlightuserdata( L, reinterpret_cast< void * >(io) );
    return 1;
}

static int open( lua_State * L )
{
    JoyCtrl * io = *reinterpret_cast<JoyCtrl * *>( lua_touserdata( L, 1 ) );
    bool res = io->open();
    lua_pushboolean( L, ( res ) ? 1 : 0 );
    return 1;
}

static int close( lua_State * L )
{
    JoyCtrl * io = *reinterpret_cast<JoyCtrl * *>( lua_touserdata( L, 1 ) );
    io->close();
    return 0;
}

static int isOpen( lua_State * L )
{
    JoyCtrl * io = *reinterpret_cast<JoyCtrl * *>( lua_touserdata( L, 1 ) );
    bool res = io->isOpen();
    lua_pushboolean( L, ( res ) ? 1 : 0 );
    return 1;
}

static int query( lua_State * L )
{
    JoyCtrl * io = *reinterpret_cast<JoyCtrl * *>( lua_touserdata( L, 1 ) );
    bool res = io->query();
    lua_pushboolean( L, res ? 1 : 0 );
    return 1;
}




static const struct luaL_reg META_FUNCTIONS[] = {
    { "__gc",          gc },
    { "pointer",       self },
    // Open/close routines
    { "open",          open },
    { "close",         close },
    { "isOpen",        isOpen },
    // The lowest possible level
    { "query",         query },

    { NULL,            NULL },
};

static void createMeta( lua_State * L )
{
    int top = lua_gettop( L );
    luaL_newmetatable( L, META );  // create new metatable for file handles
    // file methods
    lua_pushliteral( L, "__index" );
    lua_pushvalue( L, -2 );  // push metatable
    lua_rawset( L, -3 );       // metatable.__index = metatable
    luaL_register( L, NULL, META_FUNCTIONS );

    lua_settop( L, top );
}

static const struct luaL_reg FUNCTIONS[] = {
    { "create",  create },
    { NULL, NULL },
};

static void registerFunctions( lua_State * L )
{
    luaL_register( L, LIB_NAME, FUNCTIONS );
}

extern "C" int DECLSPEC luaopen_luajoyctrl( lua_State * L )
{
    createMeta( L );
    registerFunctions( L );
    return 0;
}





