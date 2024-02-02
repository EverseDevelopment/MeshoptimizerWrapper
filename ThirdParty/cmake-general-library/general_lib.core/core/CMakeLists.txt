

############################################
# assemble source files and headers
############################################

# set sources
set (SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (SOURCES	
	${SOURCES_DIR}/general_lib.cpp
	${SOURCES_DIR}/resource_handle.cpp
)
# define public headers
set (LIBRARY_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (HEADERS	
	${LIBRARY_INCLUDE_DIR}/general_lib.h
	${LIBRARY_INCLUDE_DIR}/structs.h
)
# define private headers (not exposed to users)
set (INTERNAL_HEADERS
	${SOURCES_DIR}/internal_structs.h
	${SOURCES_DIR}/internal_definitions.h
	${SOURCES_DIR}/resource_handle.h	
)



############################################
# define library target
############################################

# set libarary type
if (BUILD_TARGET_LIBRARY_TYPE_AS_SHARED)
	set (LIBRARY_TYPE SHARED)
else()
	set (LIBRARY_TYPE STATIC)
endif()
set (LIBRARY_TYPE ${LIBRARY_TYPE} CACHE STRING "is shared library" FORCE)

# set target library
add_library (${LIBRARY_NAME} 	
	# shared or static
	${LIBRARY_TYPE}
	# sources and private headers
	${SOURCES}
	${INTERNAL_HEADERS}
	# public interface
	${HEADERS}
)	



############################################
# set export header for c linkage
############################################

# generate export header
string (TOUPPER ${LIBRARY_NAME} LIBRARY_NAME_UPPERCASE)
string (TOLOWER ${LIBRARY_NAME} LIBRARY_NAME_LOWCASE)

set (GENERATED_HEADERS ${CMAKE_BINARY_DIR}/export)
set (EXPORT_MACRO_NAME "${LIBRARY_NAME_UPPERCASE}_EXPORT")
set (EXPORT_FILE_NAME "${LIBRARY_NAME_LOWCASE}_EXPORT.h")

include (GenerateExportHeader)
generate_export_header(${LIBRARY_NAME}
		BASE_NAME ${LIBRARY_NAME_UPPERCASE}
		EXPORT_MACRO_NAME ${EXPORT_MACRO_NAME}
		EXPORT_FILE_NAME ${GENERATED_HEADERS}/${EXPORT_FILE_NAME}
)

message("")
message(STATUS "---------------------------------")
message(STATUS "core library generated export header")
message(STATUS "	EXPORT_FILE_NAME: ${GENERATED_HEADERS}/${EXPORT_FILE_NAME}")
message(STATUS "	EXPORT_MACRO_NAME: ${EXPORT_MACRO_NAME}")
message("")

############################################
# define target interface and include dirs
############################################


# set include directories
target_include_directories(${LIBRARY_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		
		$<INSTALL_INTERFACE:export>
		$<BUILD_INTERFACE:${GENERATED_HEADERS}>
		
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
		${Boost_INCLUDE_DIRS}
		${JSON_INCLUDE_DIRS}
)

# set link libraries
target_link_libraries(${LIBRARY_NAME}
	${Boost_LIBRARIES}
)



############################################
# set install configuration
############################################

install (TARGETS ${LIBRARY_NAME}
	EXPORT  ${LIBRARY_EXPORT}
	RUNTIME DESTINATION  "${INSTALL_BIN_DIR}" COMPONENT bin
	LIBRARY DESTINATION  "${INSTALL_BIN_DIR}" COMPONENT shlib
	ARCHIVE DESTINATION  "${INSTALL_LIB_DIR}" COMPONENT stlib
	COMPONENT dev
)


set (LIBRARY_EXPORT ${LIBRARY_NAME}EXPORT)

install (FILES	
	${HEADERS}
	${GENERATED_HEADERS}/${EXPORT_FILE_NAME}
	DESTINATION
	${INSTALL_INCLUDE_DIR}/${LIBRARY_NAME}
)

# set library folder in solution
set_target_properties (${LIBRARY_NAME} PROPERTIES FOLDER ${CMAKE_PROJECT_NAME}/${LIBRARY_NAME})

# copy one file to output direcory using cmake copy
add_custom_command (TARGET ${LIBRARY_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${CMAKE_SOURCE_DIR}/README.md"
	$<TARGET_FILE_DIR:${LIBRARY_NAME}>
)




