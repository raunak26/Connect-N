cmake_minimum_required(VERSION 3.13)
project(ConnectN)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConnectN main.cpp ConnectN.cpp ConnectN.h Board.cpp Board.h Player.cpp Player.h Move.cpp Move.h ConnectNGame.hpp)
add_compile_options(ConnectN PRIVATE -Wall -Werror)