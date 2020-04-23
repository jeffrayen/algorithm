cmake_minimum_required(VERSION 2.8.3)
project(sort)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_compile_options(--std=c++11)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_definitions(-DDEBUG)
endif()

file(GLOB source_codes RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
foreach(source_code ${source_codes})
  string(REPLACE ".cpp" "" exe_name ${source_code})
  add_executable(${exe_name} ${source_code})
endforeach()
