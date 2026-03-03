find_package(SDL2 REQUIRED)

add_definitions(-DLV_CONF_INCLUDE_SIMPLE)

add_executable(lvgl_pc
    main_pc.c
)

target_compile_definitions(lvgl_pc PRIVATE
    LV_CONF_INCLUDE_SIMPLE
)

target_link_libraries(lvgl_pc
    lvgl
    app
    SDL2::SDL2
)

target_include_directories(lvgl_pc PRIVATE
    ../
)