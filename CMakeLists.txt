cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(trenuri)

add_executable(${PROJECT_NAME} main.cpp raylib.h)

target_link_libraries(${PROJECT_NAME})