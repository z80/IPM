
include_directories( "./src" 
                     "${ROOT}/joyctrl/src" )

file( GLOB src     "./src/*.cpp" )
file( GLOB headers "./src/*.h" )
message( STATUS "SRC = ${src}" )
message( STATUS "HEADERS = ${headers}" )

add_executable( joy_test ${src} )
set( libs joyctrl )
message( STATUS "LIBS1 = ${libs}" )
target_link_libraries( joy_test ${libs} )
install( TARGETS joy_test DESTINATION "./" )




