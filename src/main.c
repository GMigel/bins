#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "lvgl.h"

void app_create(void);

int main(int argc, char **argv)
{
    // platform/pc/main.c - at the top, after #includes
    setlocale(LC_ALL, "ru_RU.UTF-8");
    lv_textarea_set_accepted_chars(textarea, NULL); // Accept all chars

    lv_init();

    /* --- SDL driver из LVGL examples --- */

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

    lv_display_t *disp = lv_sdl_window_create(320, 240);

    lv_indev_t *mouse = lv_sdl_mouse_create();
    lv_indev_set_display(mouse, disp);

    lv_indev_t *kb = lv_sdl_keyboard_create();
    lv_indev_set_display(kb, disp);

    app_create();

    while (1)
    {
        lv_timer_handler();
        SDL_Delay(5);
    }

    return 0;
}