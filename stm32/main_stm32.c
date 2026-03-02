#include "lvgl.h"
#include "stm32_port.h"

/* from app */
void app_create(void);

int main(void)
{
    lv_init();

    stm32_port_init();   /* init display + touch */

    app_create();

    while (1)
    {
        lv_timer_handler();
        stm32_delay_ms(5);
    }
}