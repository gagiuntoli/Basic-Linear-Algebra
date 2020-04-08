
cmake_minimum_required(VERSION 3.0)

project(Basic-Linear-Algebra VERSION 0.1 LANGUAGES CXX)

include_directories(include)

file(GLOB SOURCES src/*.cpp)

add_library(bla ${SOURCES})

enable_testing()
add_subdirectory(test)
