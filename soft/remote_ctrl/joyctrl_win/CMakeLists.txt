
set( Boost_USE_STATIC_LIBS True )
set( Boost_USE_MULTITHREADED True )
find_package( Boost COMPONENTS regex REQUIRED )

aux_source_directory( "./src" src )
message( STATUS "src: \"${src}\"" )

include_directories( "./src" 
                     ${GLOB_BIN_DIR}
                     ${Boost_INCLUDE_DIRS}
		     ${ROOT}/3dparty/ftdi )

add_library( joyctrl STATIC ${src} )
target_link_libraries( joyctrl ${Boost_LIBRARIES} ${ROOT}/3dparty/ftdi/i386/ftd2xx.lib )




