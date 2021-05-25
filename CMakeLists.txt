cmake_minimum_required(VERSION 3.19)
project(HaszTejbul)

set(CMAKE_CXX_STANDARD 14)

add_executable(HaszTejbul main.cpp HashGenerator.cpp HashGenerator.h PHashTable.cpp PHashTable.h SCHashTable.cpp SCHashTable.h)