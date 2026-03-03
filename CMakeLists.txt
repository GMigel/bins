cmake_minimum_required(VERSION 3.16)
project(lvgl_multi C)

set(CMAKE_C_STANDARD 99)

option(BUILD_PC "Build PC simulator" ON)

# отключаем демо и примеры LVGL
set(LV_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(LV_BUILD_DEMOS OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/lvgl)
add_subdirectory(app)

if(BUILD_PC)
    message(STATUS "Building PC simulator")
    add_subdirectory(pc)
else()
    message(STATUS "Building STM32 target")
    add_subdirectory(stm32)
endif()