
include_directories( "./src"
                     ${CMAKE_BINARY_DIR} )

file( GLOB src     "./src/*.cpp" )
file( GLOB headers "./src/*.h" )
message( INFO "SRC = ${src}" )
message( INFO "HEADERS = ${headers}" )

add_library( binder STATIC ${src} )
target_link_libraries( binder lua-5.2.0 )

