cmake_minimum_required(VERSION 3.20)
project(Gobang)

set(CMAKE_CXX_STANDARD 14)

add_executable(Gobang main.cpp Game.cpp Game.h Player.cpp Player.h Checkerboard.cpp Checkerboard.h ChessPiece.cpp ChessPiece.h Judge.cpp Judge.h Machine.cpp Machine.h)
