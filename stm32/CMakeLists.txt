add_executable(lvgl_stm32
    main_stm32.c
    stm32_port.c
)

target_link_libraries(lvgl_stm32
    lvgl
    app
)

target_include_directories(lvgl_stm32 PRIVATE
    ${CMAKE_SOURCE_DIR}
)

# Use STM32 config instead of PC config
target_compile_definitions(lvgl_stm32 PRIVATE
    LV_CONF_PATH=\"${CMAKE_SOURCE_DIR}/lv_conf_stm32.h\"
)