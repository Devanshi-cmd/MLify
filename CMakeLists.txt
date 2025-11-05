cmake_minimum_required(VERSION 4.0)
project(MLify C)

set(CMAKE_C_STANDARD 11)

add_executable(MLify
        src_visualizer/main.c)
target_link_libraries(MLify m)

add_executable(Bresenham src_visualizer/Bresenham_circle.c)
target_link_libraries(Bresenham m)