cmake_minimum_required(VERSION 3.16)

project(topologyAPI)

set(CMAKE_CXX_STANDARD 14)

#find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(topologyAPI main.cpp topology.cpp resistance.cpp resistance.h nmos.cpp nmos.h Memory.cpp Memory.h)
