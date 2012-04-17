
set( BUILD_SHARED_LIBS ON )
include_directories( ${BOOST_INC_PATH} )
include_directories( "../lua/src" )
include_directories( "./" )
# Эта строчка потому что в MinGW не понимает, что текущая директория 
# также включена в список поиска заголовков почему-то.
include_directories( "./luabind" 
                     ${BOOST_PATH} )
list( APPEND src "./src/class.cpp" 
                 "./src/class_info.cpp" 
                 "./src/class_registry.cpp" 
                 "./src/class_rep.cpp" 
                 "./src/create_class.cpp" 
                 "./src/error.cpp" 
                 "./src/exception_handler.cpp" 
                 "./src/function.cpp" 
                 "./src/inheritance.cpp" 
                 "./src/link_compatibility.cpp" 
                 "./src/object_rep.cpp" 
                 "./src/open.cpp" 
                 "./src/pcall.cpp" 
                 "./src/scope.cpp" 
                 "./src/stack_content_by_name.cpp" 
                 "./src/weak_ref.cpp" 
                 "./src/wrapper_base.cpp" )

add_library( luabind STATIC ${src} )
target_link_libraries( luabind liblua-5.2.0 )
list( APPEND luabind_defs ${luabind_extra_defs} NDEBUG BOOST_WINDOWS )
set_property( TARGET luabind PROPERTY COMPILE_DEFINITIONS ${luabind_defs} )



