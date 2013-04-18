
find_package( Qt4 )
set( QT_USE_QT_CORE True )
include( ${QT_USE_FILE} )

include_directories( "./src" 
                     "${ROOT}/3dparty/lua-5.1.5/src" 
                     "${ROOT}/joyctrl/src" )

aux_source_directory( "./src" src )
#add_library( luajoyctrl SHARED ${src} )
#if ( WIN32 )
#   list( APPEND defs "DECLSPEC=__declspec(dllexport)" )
#endif ( WIN32 )
add_library( luajoyctrl STATIC ${src} )
set_property( TARGET luajoyctrl PROPERTY COMPILE_DEFINITIONS ${defs} )
set_property( TARGET luajoyctrl PROPERTY OUTPUT_NAME "luajoyctrl" )
set_target_properties( luajoyctrl PROPERTIES PREFIX "" )
target_link_libraries( luajoyctrl liblua-5.1.5 joyctrl )

#install( TARGETS luajoyctrl DESTINATION "./" )



