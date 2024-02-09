cmake_minimum_required(VERSION 3.27)
project(lab_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lab_1
        dict.c
        dict.h
        main.c)
