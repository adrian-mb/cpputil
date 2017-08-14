cmake_minimum_required(VERSION 3.1)

project(cpputil CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic")

add_library(cpputil STATIC Properties.cpp EnvironmentVariable.cpp)
