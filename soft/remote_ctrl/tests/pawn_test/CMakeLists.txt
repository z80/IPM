
include_directories( "./src" 
                      )

file( GLOB src     "./src/*.cpp" )
file( GLOB csrc     "./src/*.c" )
set( src ${src} ${csrc} )
file( GLOB headers "./src/*.h" )
message( STATUS "SRC = ${src}" )
message( STATUS "HEADERS = ${headers}" )

add_executable( pawn_test ${src} )
install( TARGETS pawn_test DESTINATION "./" )
install( DIRECTORY ./pawn_src DESTINATION "./" )




