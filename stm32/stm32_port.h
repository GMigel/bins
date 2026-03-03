#ifndef STM32_PORT_H
#define STM32_PORT_H

void stm32_port_init(void);
void stm32_delay_ms(uint32_t ms);
void my_flush_cb(lv_display_t *d,
                        const lv_area_t *area,
                        uint8_t *px_map);
#endif