
set( Boost_USE_STATIC_LIBS True )
set( Boost_USE_MULTITHREADED True )
find_package( Boost COMPONENTS regex REQUIRED )

find_package( Qt4 )
set( QT_USE_QTCORE    True )
set( QT_USE_QTGUI     True )
include( ${QT_USE_FILE} )

aux_source_directory( "./src" src )
message( STATUS "src: \"${src}\"" )

include( "${ROOT}/3dparty/cmake/findlibusb-1.0.cmake" )
message( STATUS ${LIBUSB_1_DEFINITIONS} )

include_directories( "./src" 
                     ${GLOB_BIN_DIR}
                     ${Boost_INCLUDE_DIRS}
		     ${ROOT}/3dparty/libftdi1-1.0/src 
		     ${ROOT}/3dparty/libftdi1-1.0/ftdipp 
                     ${ROOT}/3dparty/qextserialport/src
                     ${LIBUSB_1_INCLUDE_DIRS} )


add_library( joyctrl STATIC ${src} )
target_link_libraries( joyctrl ${Boost_LIBRARIES} ftdipp1-static ftdi1-static ${LIBUSB_1_LIBRARIES} serial ${QT_LIBRARIES} )




