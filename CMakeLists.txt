cmake_minimum_required(VERSION 3.24)
project(Clion_proj)

set(CMAKE_CXX_STANDARD 17)

add_executable(Clion_proj main.cpp elevi.in absente.in logs.log headers/mark.h "source files/mark.cpp" "source files/Grade.cpp" headers/Grade.h headers/Absence.h headers/headers.h "source files/Menu.cpp" headers/Menu.h headers/Student.h "source files/Student.cpp" "source files/Absence.cpp" "source files/Exception.cpp" headers/Exception.h)
