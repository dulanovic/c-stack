cmake_minimum_required(VERSION 3.10)
project(Stack C)

set(CMAKE_C_STANDARD 11)

add_executable(Stack src/main.c src/stack.h src/stack.c)