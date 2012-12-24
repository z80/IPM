
find_package( Qt4 REQUIRED )
set( QT_USE_QTGUI True )
include( ${QT_USE_FILE} )

include_directories( "./src"
                     "${ROOT}/mcuctrl/src"
                     ${CMAKE_CURRENT_BINARY_DIR} )

file( GLOB src     "./src/*.cpp" )
file( GLOB headers "./src/*.h" )
file( GLOB ui      "./src/*.ui" )
file( GLOB qrc     "./src/*.qrc" )
message( STATUS "SRC = ${src}" )
message( STATUS "HEADERS = ${headers}" )

qt4_wrap_cpp( moc_src ${headers} )
set( src ${src} ${moc_src} )
qt4_wrap_ui( moc_ui ${ui} )
set( src ${src} ${moc_ui} )
qt4_add_resources( moc_qrc ${qrc} )
set( src ${src} ${moc_qrc} )

add_executable( guitest  ${src} )
target_link_libraries( guitest ${QT_LIBRARIES} mcuctrl )
install( TARGETS guitest DESTINATION "." )








