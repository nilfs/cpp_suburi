cmake_minimum_required(VERSION 3.5.0)
project(suburi VERSION 0.1.0 LANGUAGES C CXX)

add_executable(suburi main.cpp)

target_include_directories(suburi PRIVATE ./src)

include(CTest)
enable_testing()

