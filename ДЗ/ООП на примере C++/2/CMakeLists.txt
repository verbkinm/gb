cmake_minimum_required(VERSION 3.5)

project(2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(2 main.cpp person.h person.cpp student.h student.cpp fruit.h fruit.cpp apple.h apple.cpp banane.h banane.cpp grannysmith.h grannysmith.cpp)
