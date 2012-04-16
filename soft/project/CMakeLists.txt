
cmake_minimum_required( VERSION 2.8 )

# ѕереопределение условий компил€ции, чтобы 
# не нужно было Microsoft Redistributable 
# устанавливать.
set(CMAKE_USER_MAKE_RULES_OVERRIDE
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/c_flag_overrides.cmake)
set(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/cxx_flag_overrides.cmake)

project( "project" )

if ( WIN32 )
    include( "./config-win32.cmake" )
elseif ( UNIX )
    include( "./config-unix.cmake" )
endif ( WIN32 )

add_subdirectory( "./3dparty/lua" )
add_subdirectory( "./3dparty/ftdi" )
#add_subdirectory( "./application" )
#add_subdirectory( "./lib-application" )
#add_subdirectory( "./lua-application" )
add_subdirectory( "./lua-app-binder" )


