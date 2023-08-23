#include "../include/prototypes.h"

static void toggle_options(raycaster_t *raycaster)
{
    static const sfKeyCode keys[] = {sfKeyComma, sfKeyPeriod, sfKeyM, -1};
    static void (*functions[])(raycaster_t *) = {
    &increase_resolution, &decrease_resolution, &toggle_mouse_view};
    static int anti_spam[3] = {0};

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
    toggle_options(raycaster);
    move_2d_player(raycaster);
    cast_rays(raycaster);
    mouse_view(window, raycaster);
}
