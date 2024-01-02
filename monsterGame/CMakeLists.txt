cmake_minimum_required(VERSION 3.26)
project(monsterGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(monsterGame main.cpp
        player.cpp
        player.h
        Monster.cpp
        Monster.h)
