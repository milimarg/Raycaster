#include <math.h>
#include "../include/prototypes.h"

static void toggle_options(raycaster_t *raycaster)
{
    static const sfKeyCode keys[] = {sfKeyUp, sfKeyDown, sfKeyLeft, sfKeyRight,
    sfKeyComma, sfKeyPeriod, sfKeyM, -1};
    static void (*functions[])(raycaster_t *) = {&move_forward, &move_backward,
    &turn_left, &turn_right, &increase_resolution, &decrease_resolution,
    &toggle_mouse_view};
    static int anti_spam[7] = {0};
    int skip_spam_for_move = 0;

    for (int i = 0; keys[i] != -1; i++) {
        skip_spam_for_move = !anti_spam[i] || (i >= 0 && i <= 4);
        if (skip_spam_for_move && sfKeyboard_isKeyPressed(keys[i])) {
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
    static int anti_spam = 0;

    if (!anti_spam && sfKeyboard_isKeyPressed(sfKeyP)) {
        anti_spam = 1;
        toggle_pause(raycaster);
    }
    if (anti_spam && !sfKeyboard_isKeyPressed(sfKeyP)) {
        anti_spam = 0;
    }
    if (!raycaster->options->elements[PAUSE]) {
        return;
    }
    raycaster->player->delta.x = cosf(deg_to_rad(raycaster->player->angle));
    raycaster->player->delta.y = sinf(deg_to_rad(raycaster->player->angle));
    toggle_options(raycaster);
    cast_rays(raycaster);
    mouse_view(window, raycaster);
}
