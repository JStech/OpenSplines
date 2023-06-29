cmake_minimum_required(VERSION 3.2)
project(opensplines)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -O3")

find_package(Eigen3)

add_executable(test_eval test/test_eval.cpp)
target_link_libraries(test_eval Eigen3::Eigen)
