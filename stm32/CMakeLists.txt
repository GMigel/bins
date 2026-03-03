project(lvgl_stm32 C ASM)

add_executable(lvgl_stm32
    main_stm32.c
    stm32_port.c

    Core/Src/main.c
    Core/Src/system_stm32h7xx.c
    Core/Startup/startup_stm32h743zitx.s
)

target_include_directories(lvgl_stm32 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    Core/Inc
    Drivers/CMSIS/Include
    Drivers/CMSIS/Device/ST/STM32H7xx/Include
    Drivers/STM32H7xx_HAL_Driver/Inc
)

target_link_libraries(lvgl_stm32
    lvgl
    app
)

# Линкерный скрипт
target_link_options(lvgl_stm32 PRIVATE
    -T${CMAKE_CURRENT_SOURCE_DIR}/STM32H743ZITX_FLASH.ld
)

# Генерация .bin
add_custom_command(TARGET lvgl_stm32 POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary lvgl_stm32 lvgl_stm32.bin
)