cmake_minimum_required(VERSION 3.10)
project(SistemaCarritoCompras)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(CarritoCompras src/main.cpp ${SOURCES})

