
include_directories( "./src"
                     "../3dparty-src/lua/src" )

file( GLOB src     "./src/*.cpp" )
file( GLOB headers "./src/*.h" )
message( INFO "SRC = ${src}" )
message( INFO "HEADERS = ${headers}" )

add_library( binder STATIC ${src} )
target_link_libraries( binder liblua-5.1.5 )

