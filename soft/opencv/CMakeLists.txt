
cmake_minimum_required( VERSION 2.6 )
project( "opencv" )
set( ROOT ${CMAKE_CURRENT_SOURCE_DIR} )
set( CMAKE_INSTALL_PREFIX ${ROOT}/build.app )
if ( WIN32 )
    include( "./config-win.cmake" )
endif ( WIN32 )
add_subdirectory( "./paper_find" )
add_subdirectory( "./qr_read" )
add_subdirectory( "./libdecodeqr" )
add_subdirectory( "./cam_calibration" )


#add_subdirectory( "./squares_extraction" )



