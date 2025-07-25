cmake_minimum_required(VERSION 3.20)

project(student_management_system)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Student class library

add_library(student STATIC src/student.cpp)

target_include_directories(student PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)





add_executable(student_management_system src/main.cpp)

target_link_libraries(student_management_system PRIVATE student)