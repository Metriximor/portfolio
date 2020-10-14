cmake_minimum_required(VERSION 3.17)
project(SGRAI)

set(CMAKE_CXX_STANDARD 20)

add_executable(SGRAI main.cpp src/Ponto2D.cpp headers/Ponto2D.h src/Circulo.cpp headers/Circulo.h)