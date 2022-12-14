cmake_minimum_required(VERSION 3.23)
project(MyDerivatives)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
add_subdirectory(libs/googletest)
include_directories(libs/googletest/include)
set(SOURCE_FILES main.cpp Functions.cpp)

add_executable(MyDerivatives ${SOURCE_FILES})
target_link_libraries(MyDerivatives gtest gtest_main)
