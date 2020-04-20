cmake_minimum_required(VERSION 3.15)
project(Inf2_labo4)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -Wpedantic")

set(CMAKE_CXX_STANDARD 11)

add_executable(Inf2_labo4 main_labo_04.cpp collection_g.h exceptions.h produit.h produit.cpp collectionImpl_g.h)