

set (SAMPLE_TARGET sample)

# set application sources
set (APP_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable (${SAMPLE_TARGET} 
	${APP_SOURCES}
)

target_link_libraries (${SAMPLE_TARGET}
	${LIBRARY_NAME}
)

set_target_properties (${SAMPLE_TARGET} PROPERTIES FOLDER ${CMAKE_PROJECT_NAME}/${LIBRARY_NAME}/${SAMPLE_TARGET})


add_dependencies (${SAMPLE_TARGET} 
	${LIBRARY_NAME}
)