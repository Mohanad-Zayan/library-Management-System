cmake_minimum_required(VERSION 3.20)
project(lms)

set(CMAKE_CXX_STANDARD 17)

add_executable(lms main.cpp User.h User.cpp Book.cpp Book.h UserList.cpp UserList.h BookList.cpp BookList.h)
