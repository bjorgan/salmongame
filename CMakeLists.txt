cmake_minimum_required(VERSION 2.8)
project(salmon)
set(CMAKE_BUILD_TYPE Release)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(salmons src/main.cpp)
