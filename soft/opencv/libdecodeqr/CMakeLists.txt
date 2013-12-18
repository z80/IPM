
set( projName "decodeqr" )

cmake_minimum_required (VERSION 2.6)

FIND_PACKAGE( OpenCV REQUIRED )

file( GLOB src ./libdecodeqr/*.cpp )
message( STATUS ${src} )

include_directories( ${OPENCV_INC_PATH} ./src )

ADD_LIBRARY( ${projName} STATIC ${src} )

set( libs ${OpenCV_LIBS} )
if ( WIN32 )
    set( libs ${libs} Ws2_32.lib )
endif ( WIN32 )
TARGET_LINK_LIBRARIES( ${projName} ${libs} )



