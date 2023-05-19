cmake_minimum_required(VERSION 3.20)
project(tema2_graphs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tema2_graphs
        pb1.cpp
        util.h
        checker.cpp)
