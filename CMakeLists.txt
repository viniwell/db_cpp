cmake_minimum_required(VERSION 3.29)
project(db_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(db_cpp
        database.cpp
        main.cpp
        database.h)
