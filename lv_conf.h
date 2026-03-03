#ifndef LV_CONF_H
#define LV_CONF_H

/* 
 * Platform selection via compile definition:
 * -DLVGL_PLATFORM_PC  → include PC config
 * otherwise           → include STM32 config
 */

#ifdef LVGL_PLATFORM_PC
    #include "config/lv_conf_pc.h"
#else
    #include "config/lv_conf_stm32.h"
#endif

#endif /* LV_CONF_H */