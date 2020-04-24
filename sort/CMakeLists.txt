cmake_minimum_required(VERSION 2.8.3)
project(sort)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)


add_compile_options(--std=c++11)
include_directories(include)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_definitions(-DDEBUG)
endif()

add_library(bubble_sort SHARED src/bubble_sort.cpp)
add_library(cocktail_sort SHARED src/cocktail_sort.cpp)
add_library(heap_sort SHARED src/heap_sort.cpp)
add_library(insertion_sort SHARED src/insertion_sort.cpp)
add_library(merge_sort SHARED src/merge_sort.cpp)
add_library(quick_sort SHARED src/quick_sort.cpp)
add_library(selection_sort SHARED src/selection_sort.cpp)
add_library(shell_sort SHARED src/shell_sort.cpp)

add_executable(sort_alg_test src/sort_alg_test.cpp)
target_link_libraries(sort_alg_test bubble_sort cocktail_sort heap_sort insertion_sort merge_sort quick_sort selection_sort shell_sort)
