cmake_minimum_required (VERSION 3.12)
project(Example LANGUAGES CXX)

# SWIG: use standard target name.
if(POLICY CMP0078)
  cmake_policy(SET CMP0078 NEW)
endif()

### import modules
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

file(GLOB SRC "*.cpp")
set_property(SOURCE Example.i PROPERTY CPLUSPLUS ON)
swig_add_library(${PROJECT_NAME}
  TYPE SHARED
  LANGUAGE go
  SOURCES Example.i ${SRC}
  )
target_include_directories(${PROJECT_NAME} PUBLIC "include/")
set_property(TARGET ${PROJECT_NAME} PROPERTY SWIG_COMPILE_OPTIONS -intgosize 64 -cgo)
