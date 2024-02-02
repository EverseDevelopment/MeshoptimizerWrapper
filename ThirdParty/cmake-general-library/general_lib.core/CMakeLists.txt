

############################################
# 3rd party
############################################

add_subdirectory (3rdparty)


############################################
# library source files
############################################

add_subdirectory (core)


############################################
# sample native application
############################################

add_subdirectory (sample)


############################################
# unittests
############################################

if (BUILD_TESTS)
	add_subdirectory (unittests_framework)
	add_subdirectory (unittests)
endif()
