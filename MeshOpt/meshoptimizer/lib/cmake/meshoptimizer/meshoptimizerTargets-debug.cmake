#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "meshoptimizer::meshoptimizer" for configuration "Debug"
set_property(TARGET meshoptimizer::meshoptimizer APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(meshoptimizer::meshoptimizer PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/meshoptimizer.lib"
  )

list(APPEND _cmake_import_check_targets meshoptimizer::meshoptimizer )
list(APPEND _cmake_import_check_files_for_meshoptimizer::meshoptimizer "${_IMPORT_PREFIX}/lib/meshoptimizer.lib" )

# Import target "meshoptimizer::gltfpack" for configuration "Debug"
set_property(TARGET meshoptimizer::gltfpack APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(meshoptimizer::gltfpack PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/gltfpack.exe"
  )

list(APPEND _cmake_import_check_targets meshoptimizer::gltfpack )
list(APPEND _cmake_import_check_files_for_meshoptimizer::gltfpack "${_IMPORT_PREFIX}/bin/gltfpack.exe" )

# Import target "meshoptimizer::gltfpacklib" for configuration "Debug"
set_property(TARGET meshoptimizer::gltfpacklib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(meshoptimizer::gltfpacklib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/gltfpacklib.lib"
  )

list(APPEND _cmake_import_check_targets meshoptimizer::gltfpacklib )
list(APPEND _cmake_import_check_files_for_meshoptimizer::gltfpacklib "${_IMPORT_PREFIX}/lib/gltfpacklib.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
