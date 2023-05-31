#include "../../include/structs.h"
#include "../../include/prototypes.h"
#include <math.h>

static void move(player_t *player, const sfVector2f *delta)
{
    sfRectangleShape_move(player->object, *delta);
    sfRectangleShape_move(player->stick_object, *delta);
    player->pos.x += delta->x;
    player->pos.y += delta->y;
}

static float fix_angle(float angle)
{
    if (angle < 0)
        angle += 2 * M_PI;
    if (angle > (2 * M_PI))
        angle -= 2 * M_PI;
    return (angle);
}

static void turn(player_t *player, float angle)
{
    sfVector2f delta = {cos(player->angle) * 5, sin(player->angle) * 5};

    player->angle = fix_angle(player->angle + angle);
    player->delta = delta;
    sfRectangleShape_setRotation(player->stick_object, player->angle * (M_PI * 20));
}

void move_2d_player(raycaster_t *raycaster)
{
    const sfKeyCode keys[] = {sfKeyUp, sfKeyDown, -1};
    const sfKeyCode turn_keys[] = {sfKeyLeft, sfKeyRight, -1};
    float angle = 0.1;
    sfVector2f move_delta = {0};

    for (int i = 0; keys[i] != -1; i++) {
        move_delta = raycaster->player->delta;
        if (sfKeyboard_isKeyPressed(keys[i])) {
            if (keys[i] == sfKeyDown) {
                move_delta.x *= -1;
                move_delta.y *= -1;
            }
            move(raycaster->player, &move_delta);
        }
    }
    for (int i = 0; turn_keys[i] != -1; i++) {
        if (sfKeyboard_isKeyPressed(turn_keys[i])) {
            turn(raycaster->player, (turn_keys[i] == sfKeyLeft) ? -angle : angle);
        }
    }
}
