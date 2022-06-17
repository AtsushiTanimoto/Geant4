cmake_minimum_required(VERSION 3.20)

project(monaco)

add_library(monaco_main SHARED
            source/main.cpp
            source/PrimaryGeneratorAction.cpp)