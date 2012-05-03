
file( GLOB src     "./src/*.cpp" )
file( GLOB headers "./src/*.h" )
include_directories( "./src" 
                     "../common" 
                     ${BOOST_INC_PATH} 
                     ${ICEE_PATH} 
                     ${CMAKE_CURRENT_BINARY_DIR} )

# Запуск slice2cpp для построения файлов, необходимых для компиляции проекта.
ADD_CUSTOM_COMMAND( 
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../common/factory.cpp 
    COMMAND ${SLICE2CPP} -I${SLICE_INC} factory.ice 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../common )
ADD_CUSTOM_COMMAND( 
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../common/pneumo.cpp 
    COMMAND ${SLICE2CPP} -I${SLICE_INC} pneumo.ice 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../common )
ADD_CUSTOM_COMMAND( 
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../common/turn_motor.cpp 
    COMMAND ${SLICE2CPP} -I${SLICE_INC} turn_motor.ice 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../common )
ADD_CUSTOM_COMMAND( 
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../common/actuator.cpp 
    COMMAND ${SLICE2CPP} -I${SLICE_INC} actuator.ice 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../common )
ADD_CUSTOM_COMMAND( 
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../common/manipulator.cpp 
    COMMAND ${SLICE2CPP} -I${SLICE_INC} manipulator.ice 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../common )

add_executable( host ${src} 
                     ${CMAKE_CURRENT_SOURCE_DIR}/../common/factory.cpp 
                     ${CMAKE_CURRENT_SOURCE_DIR}/../common/pneumo.cpp 
                     ${CMAKE_CURRENT_SOURCE_DIR}/../common/turn_motor.cpp 
                     ${CMAKE_CURRENT_SOURCE_DIR}/../common/actuator.cpp 
                     ${CMAKE_CURRENT_SOURCE_DIR}/../common/manipulator.cpp )

find_library( rpcrt4    NAMES rpcrt4.lib   PATHS  "${ROOT}/3dparty-bin" )
find_library( ws2_32    NAMES ws2_32.lib   PATHS  "${ROOT}/3dparty-bin" )
find_library( icee      NAMES icee_static.lib   PATHS "${ICEE_LIB_PATH}" )
find_library( iceec     NAMES iceec_static.lib  PATHS "${ICEE_LIB_PATH}" )
find_library( iceed     NAMES icee_staticd.lib  PATHS "${ICEE_LIB_PATH}" )
find_library( iceecd    NAMES iceec_staticd.lib PATHS "${ICEE_LIB_PATH}" )
set_property( TARGET host PROPERTY COMPILE_DEFINITIONS ICEE_STATIC_LIBS )
if ( WIN32 )
    set( libs ${rpcrt4} ${ws2_32} )
else ()
    set( libs "" )
endif ()
list( APPEND libs debug ${iceed} optimized ${icee} )
target_link_libraries( host ${libs} )

install( TARGETS host DESTINATION "./" )

