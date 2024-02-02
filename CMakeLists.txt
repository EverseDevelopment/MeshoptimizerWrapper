
project(meshoptimizer_csharp)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHa")
if (CMAKE_CXX_FLAGS_DEBUG MATCHES "/RTC1")
	string (REPLACE "/EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	string (REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
endif()
	
if (${CMAKE_VERSION} GREATER_EQUAL  3.14)
	# set cli flags baed on new property CLR intrduced in cmake version 3.14
	set_property (TARGET ${LIBRARY_BRIDGE_CLI_NAME} PROPERTY COMMON_LANGUAGE_RUNTIME "")	
else ()	
	# set manually msvc flag for common lanuage realtime
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /clr")	
endif ()

set(MESHOPT_BUILD_GLTFPACK ON)
add_subdirectory(ThirdParty/meshoptimizer EXCLUDE_FROM_ALL)

foreach(_lib_name mscorlib.dll System.dll System.Core.dll System.Data.dll System.DirectoryServices.dll System.DirectoryServices.AccountManagement.dll)
    list(APPEND _cli_compile_libs "/FU${_lib_name}")
endforeach()

add_library(MeshOpt SHARED src/test.cpp)

if(CMAKE_BUILD_TYPE MATCHES "Release|RelWithDebInfo")
    target_compile_definitions(MeshOpt PRIVATE
            UNICODE _UNICODE WIN32 _WINDOWS NDEBUG)
    target_compile_options(MeshOpt PRIVATE
            /MP /W3 /Zi /O2 /GL /Zc:__cplusplus /CLR ${_cli_compile_libs})
    target_link_options(MeshOpt PRIVATE
            /DEBUG /LTCG /NXCOMPAT /DYNAMICBASE /OPT:ICF /CLR)
else()
    target_compile_definitions(MeshOpt PRIVATE
            UNICODE _UNICODE WIN32 _WINDOWS DEBUG)
    target_compile_options(MeshOpt PRIVATE
            /MP /W3 /Zi /Od /Zc:__cplusplus /CLR ${_cli_compile_libs})
    target_link_options(MeshOpt PRIVATE
            /DEBUG /NXCOMPAT /DYNAMICBASE /CLR)
endif()

target_include_directories(MeshOpt PUBLIC include/ ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/meshoptimizer/gltf)
target_include_directories(gltfpacklib PUBLIC )

target_link_libraries(MeshOpt PRIVATE gltfpacklib)

