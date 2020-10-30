#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "InfluxData::InfluxDB" for configuration "Debug"
set_property(TARGET InfluxData::InfluxDB APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(InfluxData::InfluxDB PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/InfluxDB.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/InfluxDB.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS InfluxData::InfluxDB )
list(APPEND _IMPORT_CHECK_FILES_FOR_InfluxData::InfluxDB "${_IMPORT_PREFIX}/lib/InfluxDB.lib" "${_IMPORT_PREFIX}/bin/InfluxDB.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
