cmake_minimum_required(VERSION 3.3)
project(Dunjun)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}" )
set(SOURCE_FILES
        src/main.cpp)

add_executable(Dunjun ${SOURCE_FILES})
include_directories(include)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(Dunjun ${GLFW_LIBRARIES})

