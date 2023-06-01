#include <stdio.h>
#include <math.h>
#include "../../include/structs.h"
#include "../../include/prototypes.h"

static void move(player_t *player, const sfVector2f *delta)
{
    player->pos.x += delta->x * 5;
    player->pos.y += delta->y * 5;
    sfRectangleShape_setPosition(player->object, player->pos);
    sfRectangleShape_setPosition(player->stick_object, player->pos);
}

static void turn(player_t *player, float angle)
{
    player->angle = fix_angle(player->angle + angle);
    player->delta.x = cos(deg_to_rad(player->angle));
    player->delta.y = sin(deg_to_rad(player->angle));
    sfRectangleShape_setRotation(player->stick_object, player->angle * (M_PI * 20));
}

void move_2d_player(raycaster_t *raycaster)
{
    const sfKeyCode keys[] = {sfKeyUp, sfKeyDown, -1};
    const sfKeyCode turn_keys[] = {sfKeyLeft, sfKeyRight, -1};
    float angle = 5;
    sfVector2f move_delta = {0};

    raycaster->player->delta.x = cos(deg_to_rad(raycaster->player->angle));
    raycaster->player->delta.y = sin(deg_to_rad(raycaster->player->angle));
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
