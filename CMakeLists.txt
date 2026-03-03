cmake_minimum_required(VERSION 3.16)

project(lvgl_multi C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(BUILD_PC "Build PC simulator" ON)

# Disable demos/examples globally
set(LV_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(LV_BUILD_DEMOS OFF CACHE BOOL "" FORCE)
set(LV_USE_THORVG_INTERNAL OFF CACHE BOOL "" FORCE)

# Define platform macro (used by lv_conf.h proxy)
if(BUILD_PC)
    message(STATUS "======================================")
    message(STATUS "Building PC simulator")
    message(STATUS "======================================")
    add_compile_definitions(LVGL_PLATFORM_PC)
else()
    message(STATUS "======================================")
    message(STATUS "Building STM32 target")
    message(STATUS "======================================")
endif()

# Add LVGL core
add_subdirectory(lib/lvgl)

# Shared GUI layer
add_subdirectory(app)

# Platform specific target
if(BUILD_PC)
    add_subdirectory(pc)
else()
    add_subdirectory(stm32)
endif()