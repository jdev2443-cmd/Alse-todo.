cmake_minimum_required(VERSION 3.10)
project(biblio)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(biblio
    src/main.cpp
    src/libros.cpp
    src/biblio.cpp
)