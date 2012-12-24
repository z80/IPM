
cmake_minimum_required( VERSION 2.6 )
project( "firmwaretst" )
set( ROOT ${CMAKE_CURRENT_SOURCE_DIR} )
set( CMAKE_INSTALL_PREFIX ${ROOT}/build.app )
if ( WIN32 )
    include( "./config-win.cmake" )
endif ( WIN32 )

add_subdirectory( "./mcuctrl" )
add_subdirectory( "./mcuctrl_test" )
add_subdirectory( "./mcuctrl_guitest" )
