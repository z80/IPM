





set( S "./src" )

set( core_src  ${S}/lapi.c ${S}/lcode.c ${S}/lctype.c ${S}/ldebug.c ${S}/ldo.c ${S}/ldump.c ${S}/lfunc.c ${S}/lgc.c ${S}/llex.c ${S}/lmem.c ${S}/lobject.c ${S}/lopcodes.c ${S}/lparser.c ${S}/lstate.c ${S}/lstring.c ${S}/ltable.c ${S}/ltm.c ${S}/lundump.c ${S}/lvm.c ${S}/lzio.c )

set( lib_src  ${S}/lauxlib.c ${S}/lbaselib.c ${S}/lbitlib.c ${S}/lcorolib.c ${S}/ldblib.c ${S}/liolib.c ${S}/lmathlib.c ${S}/loslib.c ${S}/lstrlib.c ${S}/ltablib.c ${S}/loadlib.c ${S}/linit.c )

set( lua_src ${S}/lua.c )

set( luac_src ${S}/luac.c )

add_library( liblua-5.2.0 STATIC ${core_src} ${lib_src} )
add_executable( lua-5.2.0 ${lua_src} )
target_link_libraries( lua-5.2.0 liblua-5.2.0 )
add_executable( luac-5.2.0 ${luac_src} )
target_link_libraries( luac-5.2.0 liblua-5.2.0 )
