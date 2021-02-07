cmake_minimum_required(VERSION 3.19)
project(telumo)

set(CMAKE_CXX_STANDARD 20)

add_library(telumo SHARED telumo.h telumo/Table.h telumo/Entity.cpp telumo/Entity.h telumo/Scene.cpp telumo/Scene.h)