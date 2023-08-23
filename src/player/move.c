#include "../../include/prototypes.h"

void move_forward(raycaster_t *raycaster)
{
    controls_move(raycaster->player, &raycaster->player->delta);
}

void move_backward(raycaster_t *raycaster)
{
    sfVector2f move_delta = raycaster->player->delta;

    move_delta.x *= -1;
    move_delta.y *= -1;
    controls_move(raycaster->player, &move_delta);
}

void turn_left(raycaster_t *raycaster)
{
    static const float angle = 5;

    controls_turn(raycaster->player, -angle);
}

void turn_right(raycaster_t *raycaster)
{
    static const float angle = 5;

    controls_turn(raycaster->player, angle);
}
