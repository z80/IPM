
set( projName "squaresExtraction" )

cmake_minimum_required (VERSION 2.6)

FIND_PACKAGE( OpenCV REQUIRED )
find_package (OpenGL REQUIRED)

file( GLOB src ./src/*.cpp )

include_directories( ${OPENCV_INC_PATH} ./src ${ROOT}/libdecodeqr/libdecodeqr )
file(GLOB li ${OPENCV_LIB_PATH}/*.lib )

  
ADD_EXECUTABLE( ${projName} ${src} )
TARGET_LINK_LIBRARIES( ${projName} ${OpenCV_LIBS} decodeqr  )
