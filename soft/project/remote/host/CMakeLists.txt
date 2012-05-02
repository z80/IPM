
find_package( Qt4 )
set( QT_USE_QTCORE True )
set( QT_USE_QTGUI  True )
set( QT_USE_QTSCRIPT True )
set( QT_USE_QTSCRIPTTOOLS True )
include( ${QT_USE_FILE} )

file( GLOB src     "./src/*.cpp" )
file( GLOB headers "./src/*.h" )
file( GLOB ui      "./src/*.ui" )
include_directories( "./src" 
                     "../lib-app-binder/src" 
                     ${BOOST_INC_PATH} 
                     ${ROOT}/3dparty-bin/vlc-2.0.1/sdk/include
                     ${CMAKE_CURRENT_BINARY_DIR} )

# Запуск slice2cpp для построения файлов, необходимых для компиляции проекта.
ADD_CUSTOM_COMMAND( 
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../common/factory.cpp 
    COMMAND ${ICE_PATH}/cpp/bin/slice2cppe -I${ICE_PATH}/slice factory.ice 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../common )
ADD_CUSTOM_COMMAND( 
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../common/pneumo.cpp 
    COMMAND ${ICE_PATH}/cpp/bin/slice2cppe -I${ICE_PATH}/slice pneumo.ice 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../common )
ADD_CUSTOM_COMMAND( 
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../common/turn_motor.cpp 
    COMMAND ${ICE_PATH}/cpp/bin/slice2cppe -I${ICE_PATH}/slice turn_motor.ice 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../common )
ADD_CUSTOM_COMMAND( 
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../common/actuator.cpp 
    COMMAND ${ICE_PATH}/cpp/bin/slice2cppe -I${ICE_PATH}/slice actuator.ice 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../common )
ADD_CUSTOM_COMMAND( 
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../common/manipulator.cpp 
    COMMAND ${ICE_PATH}/cpp/bin/slice2cppe -I${ICE_PATH}/slice manipulator.ice 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../common )

Qt4_WRAP_CPP( mocSrc ${headers} )
set( src ${src} ${mocSrc} )

QT4_WRAP_UI( uiSrc ${ui} )
set( src ${src} ${uiSrc} )

QT4_ADD_RESOURCES( qrc "./src/images.qrc" )
set( src ${src} ${qrc} )

add_library( application STATIC ${src} 
                                ${CMAKE_CURRENT_SOURCE_DIR}/../common/factory.cpp 
                                ${CMAKE_CURRENT_SOURCE_DIR}/../common/pneumo.cpp 
                                ${CMAKE_CURRENT_SOURCE_DIR}/../common/turn_motor.cpp 
                                ${CMAKE_CURRENT_SOURCE_DIR}/../common/actuator.cpp 
                                ${CMAKE_CURRENT_SOURCE_DIR}/../common/manipulator.cpp )
find_library( libvlc NAMES libvlc PATHS "${ROOT}/3dparty-bin/vlc-2.0.1/sdk/lib" )
target_link_libraries( application ${QT_LIBRARIES} binder ${libvlc} )
install( DIRECTORY ${ROOT}/3dparty-bin/vlc-2.0.1/ DESTINATION "./" )

