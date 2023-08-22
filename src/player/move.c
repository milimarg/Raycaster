#include <math.h>
#include "../../include/prototypes.h"

static void handle_tank_controls(raycaster_t *raycaster, const float angle)
{
    static const sfKeyCode keys[] = {sfKeyUp, sfKeyDown, -1};
    static const sfKeyCode turn_keys[] = {sfKeyLeft, sfKeyRight, -1};
    sfVector2f move_delta = {0};
    float move_angle = 0;

    for (int i = 0; keys[i] != -1; i++) {
        move_delta = raycaster->player->delta;
        if (sfKeyboard_isKeyPressed(keys[i])) {
            if (keys[i] == sfKeyDown) {
                move_delta.x *= -1;
                move_delta.y *= -1;
            }
            controls_move(raycaster->player, &move_delta);
        }
    }
    for (int i = 0; turn_keys[i] != -1; i++) {
        if (sfKeyboard_isKeyPressed(turn_keys[i])) {
            move_angle = (turn_keys[i] == sfKeyLeft) ? -angle : angle;
            tank_controls_turn(raycaster->player, move_angle);
        }
    }
}

void move_2d_player(raycaster_t *raycaster)
{
    static const float angle = 5;

    raycaster->player->delta.x = cosf(deg_to_rad(raycaster->player->angle));
    raycaster->player->delta.y = sinf(deg_to_rad(raycaster->player->angle));
    handle_tank_controls(raycaster, angle);
}
