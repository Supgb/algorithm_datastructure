cmake_minimum_required(VERSION 3.0)

project(program_analyze)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

include_directories(../Iterator ../Stack ../Chain ../LinearList)

add_executable(program_analyze LinkedStack.cpp)
