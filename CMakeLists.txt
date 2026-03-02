cmake_minimum_required(VERSION 3.16)
project(lvgl_multi)

set(CMAKE_C_STANDARD 99)

add_subdirectory(lib/lvgl)

add_subdirectory(app)
add_subdirectory(pc)
add_subdirectory(stm32)