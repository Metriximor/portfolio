cmake_minimum_required(VERSION 3.17)
project(Relogio)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_SOURCE_DIR .)

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/src/*.c
        ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES
        ${CMAKE_SOURCE_DIR}/src/*.h)

include_directories(
        ${CMAKE_SOURCE_DIR}/lib/GLUT
        ${CMAKE_SOURCE_DIR}/src)

link_directories(${CMAKE_SOURCE_DIR}/lib/GLUT)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})