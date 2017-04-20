cmake_minimum_required(VERSION 2.6)
project(impc)

add_executable(impc main.cpp)

install(TARGETS impc RUNTIME DESTINATION bin)
