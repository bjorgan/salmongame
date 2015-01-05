cmake_minimum_required(VERSION 2.8)
project(salmon)
FIND_PACKAGE(Qt4 REQUIRED)
set(CMAKE_BUILD_TYPE Debug)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#compile and link
add_executable(salmons)
