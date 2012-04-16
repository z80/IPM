
aux_source_directory( "./src" src )

include_directories( "./src" )
if ( WIN32 )
    message( STATUS "LIBUSB_INC_PATH: ${LIBUSB_INC_PATH}" )
    include_directories( ${LIBUSB_INC_PATH} )
endif ( WIN32 )

add_library( libftdi STATIC ${src} )
message( STATUS "LIBUSB_LIB_PATH: ${LIBUSB_LIB_PATH}" )
find_library( libusb NAMES libusb.o libusb.lib PATHS $ENV{PATH} ${LIBUSB_LIB_PATH} )
target_link_libraries( libftdi ${libusb} )
