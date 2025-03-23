cmake_minimum_required(VERSION 3.23)
project(XD)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(XD
        .idea/.gitignore
        .idea/encodings.xml
        .idea/modules.xml
        .idea/workspace.xml
        .idea/XD.iml
        main.cpp)
