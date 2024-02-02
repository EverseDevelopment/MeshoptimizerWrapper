

############################################
# Import gtest project
############################################

add_subdirectory (gtest-1.6.0)
set_target_properties (gtest_main PROPERTIES FOLDER ${CMAKE_PROJECT_NAME}/${LIBRARY_NAME}/3rdparty/gtest)
set_target_properties (gtest PROPERTIES FOLDER ${CMAKE_PROJECT_NAME}/${LIBRARY_NAME}/3rdparty/gtest)


############################################
# boost libraries
############################################

# enable boost by defualt
option(Boost_Enable "build solution with boost libraries" ON)
if (Boost_Enable)
	if (NOT DEFINED BOOST_ROOT_PATH)
		set (BOOST_ROOT_PATH "C:/local/boost_1_68_0" CACHE STRING "boost root directory path" FORCE)
	endif()

	set (BOOST_ROOT ${BOOST_ROOT_PATH} CACHE STRING "boot root directory" FORCE)
	set (Boost_USE_STATIC_LIBS 	ON CACHE BOOL "" FORCE)
	set (Boost_USE_MULTITHREADED ON CACHE BOOL "" FORCE)
	set (Boost_USE_STATIC_RUNTIME OFF CACHE BOOL "" FORCE)
	set (Boost_NO_SYSTEM_PATH ON CACHE BOOL "" FORCE)

	find_package (Boost REQUIRED 
		thread
	)
endif()


# Make the boost libararies / include directories cmake variable persistent by saving it to cache for later use
set (Boost_INCLUDE_DIRS ${Boost_INCLUDE_DIRS} CACHE STRING "boost include directories" FORCE)
set (Boost_LIBRARIES ${Boost_LIBRARIES} CACHE STRING "boost libraries" FORCE)

message("")
message(STATUS "---------------------------------")
message(STATUS "Boost libraries")
message(STATUS "	BOOST_ROOT: ${BOOST_ROOT}")
message(STATUS "	Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "	Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "	Boost_USE_STATIC_LIBS: ${Boost_USE_STATIC_LIBS}")
message(STATUS "	Boost_USE_MULTITHREADED: ${Boost_USE_MULTITHREADED}")
message(STATUS "	Boost_USE_STATIC_RUNTIME: ${Boost_USE_STATIC_RUNTIME}")
message(STATUS "	Boost_NO_SYSTEM_PATH: ${Boost_NO_SYSTEM_PATH}")
message("")

############################################
# json libraries
############################################

set (JSON_INCLUDE_DIRS "${3RD_PARTY_ROOT}/json" CACHE STRING "json include directories" FORCE)

message("")
message(STATUS "---------------------------------")
message(STATUS "Json header")
message(STATUS "	JSON_INCLUDE_DIRS: ${JSON_INCLUDE_DIRS}")
message("")

