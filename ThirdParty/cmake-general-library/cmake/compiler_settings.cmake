
###############################################
# set cmake version and compiler configurations
###############################################

# set cmake compiler build configuration
if (NOT DEFINED CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE "Debug" CACHE STRING "build configuration" FORCE)
endif()

# find target machine compiler arch
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
	set (ARCH "x64" CACHE STRING "target compiler architecture based on x64" FORCE)
else (CMAKE_SIZEOF_VOID_P EQUAL 4)
	set (ARCH "x86" CACHE STRING "target compiler architecture based on x86" FORCE)
endif()

option (BUILD_TESTS "build gtests as part of solution" ON)

set (CMAKE_VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} CACHE STRING "current cmake version" FORCE)

if (MSVC)
	
	# adding compiler definitions and flags
	add_definitions (-D_SCL_SECURE_NO_WARNINGS)
	add_definitions (-D_CRT_SECURE_NO_WARNINGS)
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W0")
	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Zi")
	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Gy")
	# enable directories hierarchy in visual studio projects
	set_property (GLOBAL PROPERTY USE_FOLDERS ON)
	
	# support c++17 for target MSVC
	include (CheckCXXCompilerFlag)
	CHECK_CXX_COMPILER_FLAG ("/std:c++latest" _cpp_latest_flag_supported)
	if (_cpp_latest_flag_supported)
		add_compile_options("/std:c++latest")
	endif()
else (CMAKE_COMPILER_IS_GNUCC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

# Export no symbols by default (no windows this is no-op)
set (CMAKE_C_VISABILITY_PRESENT hidden)
set (CMAKE_CXX_VISABILITY_PRESENT hidden)

# enable c# compiler settings
enable_language(CSharp)
if (NOT DEFINED DOTNET_TARGET_FRAMEWORK_VERSION)
	set (DOTNET_TARGET_FRAMEWORK_VERSION "v4.5.1" CACHE STRING ".NET framework version" FORCE)
endif()

message ("")
message (STATUS "---------------------------------")
message (STATUS "COMPILER INFO: ")
message (STATUS "	CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")
message (STATUS "	CMAKE_VERSION: ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}")
message (STATUS "	ARCHITECTURE: ${ARCH}")
message (STATUS "	CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message (STATUS "	CHECK_CXX_COMPILER_FLAG: ${_cpp_latest_flag_supported}")
message (STATUS "	CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
message (STATUS "	DOTNET_TARGET_FRAMEWORK_VERSION: ${DOTNET_TARGET_FRAMEWORK_VERSION}")
message (STATUS "	PROJECT_BINARY_DIRECTORY: ${PROJECT_BINARY_DIR}")
message ("")






