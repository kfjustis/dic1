cmake_minimum_required (VERSION 2.8)

project(dic1)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

add_executable (dic1 ./src/dic1.c)
target_link_libraries(${PROJECT_NAME} m)
