cmake_minimum_required(VERSION 3.27)
project(Final_Project_)

set(CMAKE_CXX_STANDARD 17)

add_executable(Final_Project_ main.cpp
        cmake-build-debug/Cards.cpp
        cmake-build-debug/Cards.h
        cmake-build-debug/Dealer.cpp
        cmake-build-debug/Dealer.h
        cmake-build-debug/Player.cpp
        cmake-build-debug/Player.h)
