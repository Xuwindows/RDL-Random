cmake_minimum_required(VERSION 4.1)
project(rdl-random)

set(CMAKE_CXX_STANDARD 23)

include_directories(Include)

add_executable(Random
        Source/RDLRandom.cpp)
