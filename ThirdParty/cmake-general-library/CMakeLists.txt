cmake_minimum_required (VERSION 3.11)
project (general_lib VERSION 1.0.0)

#set compiler settings
include (${CMAKE_SOURCE_DIR}/cmake/compiler_settings.cmake)

#set cmake project configuration for this project
include (${CMAKE_SOURCE_DIR}/cmake/configuration.cmake)


############################################
# core library with unittests and executable
############################################
add_subdirectory (${LIBRARY_FOLDER_NAME_CPP})


############################################
# cli bridge
############################################

add_subdirectory (${LIBRARY_FOLDER_NAME_CLI})


############################################
# c# wrapper
############################################

add_subdirectory (${LIBRARY_FOLDER_NAME_CSHARP})


############################################
# c# sample application
############################################

add_subdirectory (apps)