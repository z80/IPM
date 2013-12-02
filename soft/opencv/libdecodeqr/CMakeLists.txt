
set( projName "decodeqr" )

cmake_minimum_required (VERSION 2.6)

FIND_PACKAGE( OpenCV REQUIRED )

file( GLOB src ./libdecodeqr/*.cpp )
message( STATUS ${src} )

include_directories( ${OPENCV_INC_PATH} ./src )

ADD_LIBRARY( ${projName} STATIC ${src} )
TARGET_LINK_LIBRARIES( ${projName} ${OpenCV_LIBS} )



