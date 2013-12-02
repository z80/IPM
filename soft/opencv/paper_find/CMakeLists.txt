
set( projName "sheetDetector" )

cmake_minimum_required (VERSION 2.6)

FIND_PACKAGE( OpenCV REQUIRED )
find_package (OpenGL REQUIRED)

file( GLOB src ./src/*.cpp )
message( STATUS ${src} )

include_directories( ${OPENCV_INC_PATH} ./src )
file(GLOB li ${OPENCV_LIB_PATH}/*.lib )
message( STATUS ${li} )

set( libs "" )
foreach( f ${li})
         set( libs ${libs} debug ${f} )
endforeach()
message( STATUS ${libs} )
message( STATUS ${OpenCV_LIBS} )
  
ADD_EXECUTABLE( ${projName} ${src} )
TARGET_LINK_LIBRARIES( ${projName} ${OpenCV_LIBS} )
