
find_package( Qt4 )
set( QT_USE_QTCORE True )
set( QT_USE_QTGUI  True )
if ( WIN32 )
    set( QT_USE_QTMAIN True )
endif ( WIN32 )
include( ${QT_USE_FILE} )

include_directories( "./src" 
                     "../lib-application/src" )

aux_source_directory( "./src" src )

if ( WIN32 )
    set( BLD_TYPE WIN32 )
elseif ( UNIX )
    set( BLD_TYPE "" )
endif (WIN32)

add_executable( ctrl ${BLD_TYPE} ${src} )
target_link_libraries( ctrl application ${QT_LIBRARIES} )
install( TARGETS ctrl DESTINATION "." )

