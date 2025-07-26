cmake_minimum_required(VERSION 3.20)

project(student_management_system)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Student class library

add_library(student STATIC src/student.cpp)

target_include_directories(student PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)







add_executable(student_management_system
src/main.cpp
)

target_link_libraries(student_management_system PRIVATE student)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  student_test
  src/student_test.cc
)
target_link_libraries(
  student_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(student_test)