cmake_minimum_required(VERSION 3.19)
project(Quadrocopter)

set(CMAKE_CXX_STANDARD 20)

add_executable(Quadrocopter main.cpp Waypoints/WayPoint.cpp Waypoints/WayPointContainer.cpp QuadroCopter.cpp)
