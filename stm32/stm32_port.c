#include "lvgl.h"
#include "stm32_port.h"

/* Replace with HAL includes */
#include "stm32h7xx_hal.h"

static lv_display_t *disp;
static lv_color_t buf1[480 * 10]; /* example buffer */

void stm32_port_init(void)
{
    /* LCD + LTDC init here (CubeMX generated) */

    disp = lv_display_create(320, 240);

    lv_display_set_flush_cb(disp, my_flush_cb);
    lv_display_set_buffers(disp, buf1, NULL,
                           sizeof(buf1),
                           LV_DISPLAY_RENDER_MODE_PARTIAL);
}

void stm32_delay_ms(uint32_t ms)
{
    HAL_Delay(ms);
}

/* Example flush callback */
void my_flush_cb(lv_display_t *d,
                 const lv_area_t *area,
                 uint8_t *px_map)
{
    /* Copy to framebuffer here */

    lv_display_flush_ready(d);
}