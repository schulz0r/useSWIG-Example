cmake_minimum_required (VERSION 3.12)
project(Example LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 11)

# SWIG: use standard target name.
if(POLICY CMP0078)
  cmake_policy(SET CMP0078 NEW)
endif()

### import modules
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

# build library first
file(GLOB SRC "src/*.cpp")
file(GLOB HEADERS "include/*.h")

set_property(SOURCE Example.i PROPERTY CPLUSPLUS ON)

swig_add_library(${PROJECT_NAME}
  TYPE SHARED
  LANGUAGE go
  OUTPUT_DIR $ENV{GOPATH}/src/example # path where go looks for source code by default
  SOURCES Example.i ${SRC}
  )
target_include_directories(${PROJECT_NAME} PUBLIC "include/")
set_property(TARGET ${PROJECT_NAME} PROPERTY SWIG_COMPILE_OPTIONS -intgosize 64 -cgo)

# Copy header files to go module. Otherwise, go build/install will not work
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${HEADERS} $ENV{GOPATH}/src/example)
