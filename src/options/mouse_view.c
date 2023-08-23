#include <math.h>
#include "../../include/prototypes.h"

void mouse_view(sfRenderWindow *window, raycaster_t *raycaster)
{
    static const float angle = 5;
    static sfVector2i prev = {0};
    sfVector2i current = {0};
    sfVector2i delta = {0};
    float move_angle;

    if (!raycaster->options->elements[MOUSE_VIEW]) {
        return;
    }
    current = sfMouse_getPositionRenderWindow(window);
    delta = (sfVector2i){current.x - prev.x, current.y - prev.y};
    move_angle = (delta.x < 0) ? -angle : angle;
    if (fabsf((float)delta.x) > 10 && fabsf((float)delta.y) < 8) {
        controls_turn(raycaster->player, move_angle * 2);
    }
    prev = current;
}

void toggle_mouse_view(raycaster_t *raycaster)
{
    invert_variable(&raycaster->options->elements[MOUSE_VIEW]);
}
