cmake_minimum_required(VERSION 3.3)
project(Dunjun_game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp include/Dunjun/Common.hpp)
add_executable(Dunjun_game ${SOURCE_FILES})

include_directories(include)