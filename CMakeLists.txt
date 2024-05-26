cmake_minimum_required(VERSION 3.26)
project(SortingMiniProj__1_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SortingMiniProj__1_
        main.cpp
        Sort.cpp
        Sort.hpp
        testSort.cpp
        testSort.hpp)
