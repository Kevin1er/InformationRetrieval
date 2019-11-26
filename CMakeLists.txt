cmake_minimum_required(VERSION 3.5)

project(InformationRetrieval LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(InformationRetrieval src/RI.cpp src/RI.h src/Index.cpp src/Index.h)
