cmake_minimum_required(VERSION 2.6)
project(impc)


find_package(YCM REQUIRED)
include(YCMDefaultDirs)

find_package(iDynTree REQUIRED)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(Eigen3 REQUIRED)


include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})

include_directories(include)
