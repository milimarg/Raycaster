#include "../include/prototypes.h"

static void toggle_events(raycaster_t *raycaster)
{
    static const sfKeyCode keys[] = {sfKeyComma, sfKeyPeriod, sfKeyM, sfKeyP, -1};
    static void (*functions[])(raycaster_t *) = {
    &increase_resolution, &decrease_resolution, &toggle_mouse_view,
    &toggle_pause};
    static int anti_spam[4] = {0};

    for (int i = 0; keys[i] != -1; i++) {
        if (!anti_spam[i] && sfKeyboard_isKeyPressed(keys[i])) {
            anti_spam[i] = 1;
            functions[i](raycaster);
        }
        if (anti_spam[i] && !sfKeyboard_isKeyPressed(keys[i])) {
            anti_spam[i] = 0;
        }
    }
}

void update(raycaster_t *raycaster, sfRenderWindow *window)
{
    toggle_events(raycaster);
    move_2d_player(raycaster);
    cast_rays(raycaster);
    mouse_view(window, raycaster);
    pause(raycaster);
}
