# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\WarehouseSystem_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\WarehouseSystem_autogen.dir\\ParseCache.txt"
  "WarehouseSystem_autogen"
  )
endif()
