#CMake version
cmake_minimum_required(VERSION 3.17)

#Project name
project(SGRAI)

#Flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_SOURCE_DIR .)

#Files
file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES
        ${CMAKE_SOURCE_DIR}/src/*.h)

#Include
include_directories(
        ${CMAKE_SOURCE_DIR}/lib/GLUT
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/include)

#External Libs
link_directories(${CMAKE_SOURCE_DIR}/lib/GLUT)

#Target
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
