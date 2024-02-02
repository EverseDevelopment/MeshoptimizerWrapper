
set (UNITTEST_FW_LIBRARY unittests_framework)



############################################
# assemble source files and headers
############################################

# set sources
set (UNITTEST_FWS_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (UNITTEST_FWS_SOURCE
	${UNITTEST_FWS_SOURCE_DIR}/unittest_core.cpp
)

# define public headers
set (UNITTEST_FWS_INCLUDE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (UNITTEST_FWS_HEADERS
	${UNITTEST_FWS_INCLUDE_DIR}/json_fixture.h
	${UNITTEST_FWS_INCLUDE_DIR}/unittest_core.h
	${JSON_INCLUDE_DIRS}/json.hpp
)


############################################
# define library target
############################################


add_library (${UNITTEST_FW_LIBRARY} 
		# shared or static based on library 
		${LIBRARY_TYPE}
		# sources and private headers
		${UNITTEST_FWS_SOURCE}
		# public interface
		${UNITTEST_FWS_HEADERS}
)



############################################
# set export header for c linkage
############################################

# generate export header
string (TOUPPER ${UNITTEST_FW_LIBRARY} UNITTEST_FW_LIBRARY_UPPERCASE)
string (TOLOWER ${UNITTEST_FW_LIBRARY} UNITTEST_FW_LIBRARY_LOWCASE)

set (GENERATED_HEADERS ${CMAKE_BINARY_DIR}/export)
set (EXPORT_MACRO_NAME "${UNITTEST_FW_LIBRARY_UPPERCASE}_EXPORT")
set (EXPORT_FILE_NAME "${UNITTEST_FW_LIBRARY_LOWCASE}_EXPORT.h")

include (GenerateExportHeader)
generate_export_header(${UNITTEST_FW_LIBRARY}
		BASE_NAME ${UNITTEST_FW_LIBRARY_UPPERCASE}
		EXPORT_MACRO_NAME ${EXPORT_MACRO_NAME}
		EXPORT_FILE_NAME ${GENERATED_HEADERS}/${EXPORT_FILE_NAME}
)

message("")
message(STATUS "---------------------------------")
message(STATUS "unittest library framework generated export header")
message(STATUS "	EXPORT_FILE_NAME: ${GENERATED_HEADERS}/${EXPORT_FILE_NAME}")
message(STATUS "	EXPORT_MACRO_NAME: ${EXPORT_MACRO_NAME}")
message("")



############################################
# define target interface and include dirs
############################################

# set include directories
target_include_directories (${UNITTEST_FW_LIBRARY} 
	
	PUBLIC
		$<BUILD_INTERFACE:
			${UNITTEST_FWS_INCLUDE_DIR}
			${gtest_SOURCE_DIR}/include
			${JSON_INCLUDE_DIRS}
			${GENERATED_HEADERS}>
		
		$<INSTALL_INTERFACE:
			include
			export>
)



# Standard linking to gtest stuff.
target_link_libraries (${UNITTEST_FW_LIBRARY}  
		gtest 
		gtest_main
)

add_dependencies (${UNITTEST_FW_LIBRARY}  
		gtest 
		gtest_main
)


############################################
# set install configuration
############################################

set (UNITTEST_FW_LIBRARY_EXPORT ${UNITTEST_FW_LIBRARY}EXPORT)

install (TARGETS ${UNITTEST_FW_LIBRARY}
	EXPORT  ${UNITTEST_FW_LIBRARY_EXPORT}
	RUNTIME DESTINATION  "${INSTALL_BIN_DIR}" COMPONENT bin
	LIBRARY DESTINATION  "${INSTALL_BIN_DIR}" COMPONENT shlib
	ARCHIVE DESTINATION  "${INSTALL_LIB_DIR}" COMPONENT stlib
	COMPONENT dev
)


install (FILES	
	${HEADERS}
	${GENERATED_HEADERS}/${EXPORT_FILE_NAME}
	DESTINATION
	${INSTALL_INCLUDE_DIR}/${UNITTEST_FW_LIBRARY}
)

set (UNITTEST_FWS_INCLUDE_DIR ${UNITTEST_FWS_INCLUDE_DIR} CACHE STRING "is shared library" FORCE)
set (UNITTEST_FW_LIBRARY ${UNITTEST_FW_LIBRARY} CACHE STRING "is shared library" FORCE)

set_target_properties(${UNITTEST_FW_LIBRARY} PROPERTIES FOLDER ${CMAKE_PROJECT_NAME}/${LIBRARY_NAME}/unittests)


