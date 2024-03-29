project(data_broker)
set(PROJECT_VERSION 1.0)
set(PROJECT_DESCRIPTION "A small library to manage data communication within a software framework.")
cmake_minimum_required(VERSION 2.6)

include(FindPkgConfig)

find_package(lib_manager)
lib_defaults()
define_module_info()

pkg_check_modules(PKGCONFIG REQUIRED
                  lib_manager
                  mars_utils
)

include_directories(${PKGCONFIG_INCLUDE_DIRS})
link_directories(${PKGCONFIG_LIBRARY_DIRS})
add_definitions(${PKGCONFIG_CFLAGS_OTHER})  # flags without -I

#if(NOT ${CMAKE_C_SIZEOF_DATA_PTR} EQUAL 8)
#  set(DATA_BROKER_EIGEN_DEFINITIONS -DEIGEN_DONT_ALIGN=1)
#  add_definitions(${DATA_BROKER_EIGEN_DEFINITIONS})
#endif()

include_directories(
  src
)


set(SOURCES
    src/DataBroker.cpp
    src/DataPackage.cpp
    src/DataPackageMapping.cpp
    src/DataItem.cpp
    src/DataInfo.cpp
)

set(HEADERS
    src/DataBrokerInterface.h
    src/ProducerInterface.h
    src/ReceiverInterface.h
    src/DataBroker.h
    src/DataPackage.h
    src/DataPackageMapping.h
    src/DataItem.h
    src/DataInfo.h
    src/LockableContainer.h
)



add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_link_libraries(${PROJECT_NAME}
                      ${PKGCONFIG_LIBRARIES}
                      -lpthread
)

if(WIN32)
  set(LIB_INSTALL_DIR bin) # .dll are in PATH, like executables
else(WIN32)
  set(LIB_INSTALL_DIR lib)
endif(WIN32)


set(_INSTALL_DESTINATIONS
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION ${LIB_INSTALL_DIR}
  ARCHIVE DESTINATION lib
)


# Install the library into the lib folder
install(TARGETS ${PROJECT_NAME} ${_INSTALL_DESTINATIONS})

# Install headers into mars include directory
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})

# Prepare and install necessary files to support finding of the library
# using pkg-config
configure_file(${PROJECT_NAME}.pc.in ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc DESTINATION lib/pkgconfig)


