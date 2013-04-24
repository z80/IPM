
find_package( Qt4 )
set( QT_USE_QTCORE    True )
set( QT_USE_QTGUI     True )
include( ${QT_USE_FILE} )

aux_source_directory( "./src" src )
message( STATUS "src: \"${src}\"" )

include( "${ROOT}/3dparty/cmake/findlibusb-1.0.cmake" )
message( STATUS ${LIBUSB_1_DEFINITIONS} )

include_directories( "./src" )
if ( WIN32 )
    include_directories( ${ROOT}/joyctrl_win/src )
else ( WIN32 )
    include_directories( ${ROOT}/joyctrl/src )
endif ( WIN32 )

add_library( joyctrl_top STATIC ${src} )
target_link_libraries( joyctrl_top joyctrl ${QT_LIBRARIES} )




