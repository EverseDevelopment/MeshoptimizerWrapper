
###############################################
# library configuration
###############################################

# set core library name
set (LIBRARY_NAME core CACHE STRING "library name" FORCE)
set (LIBRARY_FOLDER_NAME_CPP ${CMAKE_PROJECT_NAME}.${LIBRARY_NAME} CACHE STRING "library folder" FORCE)

# set bridge library name
set (LIBRARY_BRIDGE_CLI_NAME cli.bridge CACHE STRING "cli bridge library name" FORCE)
set (LIBRARY_FOLDER_NAME_CLI ${CMAKE_PROJECT_NAME}.${LIBRARY_BRIDGE_CLI_NAME} CACHE STRING "cli folder name" FORCE)

# set c# wrapper library name
set (LIBRARY_CSHARP_NAME wrapper CACHE STRING "c# wrapper library name" FORCE)
set (LIBRARY_FOLDER_NAME_CSHARP ${CMAKE_PROJECT_NAME}.${LIBRARY_CSHARP_NAME} CACHE STRING "c# wrapper folder name" FORCE)


# set installation folders
set (INSTALL_LOCATION "${PROJECT_BINARY_DIR}/install" CACHE STRING "install directory" FORCE)

set (INSTALL_LIB_DIR "${INSTALL_LOCATION}/lib" CACHE PATH "Installation of libraries")
set (INSTALL_BIN_DIR "${INSTALL_LOCATION}/bin" CACHE PATH "Installation of executables")
set (INSTALL_INCLUDE_DIR "${INSTALL_LOCATION}/include" CACHE PATH "Installation of includes")

if (WIN32 AND NOT CYGWIN)
	set (DEF_INSTALL_CMAKE_DIR CMake)
else()
	set (DEF_INSTALL_CMAKE_DIR lib/CMake/${CMAKE_PROJECT_NAME})
endif()

# Make relative path absolute
foreach (p LIB_BIN INCLUDE CMAKE)
	set (var INSTALL_{p}_DIR)
	if (NOT IS_ABSOLUTE "${${var}}")
		set (${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
	endif()
endforeach()

# set Export for all targets
set (LIBRARAY_EXPORT ${LIBRARY_NAME}EXPORT)

# set path of cmake generated files
set (PROJECT_CMAKE_FILES ${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY})

# set rpath to be used when installed
set (CMAKE_INSTALL_RPATH ${INSTALL_LIB_DIR})

# define 3rdparty root directory
if (NOT DEFINED 3RD_PARTY_ROOT)
	set (3RD_PARTY_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_FOLDER_NAME_CPP}/3rdparty" CACHE STRING "third party root" FORCE)
endif()

#  set output directories
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# build target as shared lib so the static gtest library need to be shared as well in order to link correctly
option (BUILD_TARGET_LIBRARY_TYPE_AS_SHARED "build target as shared" ON)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

option (BUILD_TESTS "build unittests" ON)


message("")
message(STATUS "---------------------------------")
message(STATUS "${LIBRARY_NAME} configuration")
message(STATUS "	LIBRARY_FOLDER_NAME_CPP: ${LIBRARY_FOLDER_NAME_CPP}")
message(STATUS "	LIBRARY_BRIDGE_CLI_NAME: ${LIBRARY_BRIDGE_CLI_NAME}")
message(STATUS "	LIBRARY_CSHARP_NAME: ${LIBRARY_CSHARP_NAME}")
message(STATUS "	LIBRARY_FOLDER_NAME_CSHARP: ${LIBRARY_FOLDER_NAME_CSHARP}")
message(STATUS "	BUILD_TARGET_LIBRARY_TYPE_AS_SHARED: ${BUILD_TARGET_LIBRARY_TYPE_AS_SHARED}")
message(STATUS "	BUILD_TESTS: ${BUILD_TESTS}")
message(STATUS "	PROJECT_CMAKE_FILES: ${PROJECT_CMAKE_FILES}")
message(STATUS "	INSTALL_LIB_DIR: ${INSTALL_LIB_DIR}")
message(STATUS "	INSTALL_BIN_DIR: ${INSTALL_BIN_DIR}")
message(STATUS "	INSTALL_INCLUDE_DIR: ${INSTALL_INCLUDE_DIR}")
message(STATUS "	CMAKE_ARCHIVE_OUTPUT_DIRECTORY: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(STATUS "	CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "	CMAKE_LIBRARY_OUTPUT_DIRECTORY: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message("")





