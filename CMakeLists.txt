cmake_minimum_required(VERSION 3.22)
project(CadExchangerTest)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CadExchangerTest
        circle.h
        curve_3d.h
        elipse.h
        helix.h
        main.cpp
        point_3d.h)
