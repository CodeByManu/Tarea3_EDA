cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER "/usr/bin/c++")

# set the project name

project(calculadora
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_subdirectory(src)
#add_subdirectory(tests)

add_executable(test main.cpp code/source/infToPost.cpp code/source/abb.cpp code/source/abbNode.cpp code/source/postToTree.cpp)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/include)

# add the executable