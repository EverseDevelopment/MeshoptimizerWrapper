
# set sources for cli project
set (SOURCES_DIR_CLI ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (SOURCES_CLI
	${SOURCES_DIR_CLI}/GeneralLib.cpp
	${SOURCES_DIR_CLI}/AssemblyInfo.cpp
)


# set headers for cli project
set (INCLUDE_DIR_CLI ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (HEADERS_CLI
	${INCLUDE_DIR_CLI}/GeneralLib.h
	${INCLUDE_DIR_CLI}/ManagedObject.h
)

# define target
add_library (${LIBRARY_BRIDGE_CLI_NAME} ${LIBRARY_TYPE}
	${SOURCES_CLI}
	${HEADERS_CLI}
)


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




# define include directories for target
target_include_directories (${LIBRARY_BRIDGE_CLI_NAME}
	PRIVATE
		${INCLUDE_DIR}
)

# link cli project with core library
target_link_libraries (${LIBRARY_BRIDGE_CLI_NAME} ${LIBRARY_NAME})

set_target_properties (${LIBRARY_BRIDGE_CLI_NAME} PROPERTIES FOLDER ${CMAKE_PROJECT_NAME}/${LIBRARY_BRIDGE_CLI_NAME}) 

# make sure that core library will be compiled before cli 
add_dependencies(${LIBRARY_BRIDGE_CLI_NAME} ${LIBRARY_NAME})