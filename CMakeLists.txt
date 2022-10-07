cmake_minimum_required(VERSION 3.23)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)

add_executable(WordCount main.cpp)

set(CMAKE_EXE_LINKER_FLAGS "--static")