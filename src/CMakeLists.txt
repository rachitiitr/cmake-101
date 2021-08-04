cmake_minimum_required(VERSION 3.2)
project(MyApp)
add_subdirectory(utils)
add_executable(myExe main.cpp utils/math.cpp)

