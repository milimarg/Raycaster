#include <math.h>
#include "../../include/prototypes.h"

void controls_move(player_t *player, const sfVector2f *delta)
{
    player->pos.x += delta->x * 5;
    player->pos.y += delta->y * 5;
    sfRectangleShape_setPosition(player->object, player->pos);
}

void tank_controls_turn(player_t *player, float angle)
{
    player->angle = fix_angle(player->angle + angle);
    player->delta.x = cosf(deg_to_rad(player->angle));
    player->delta.y = sinf(deg_to_rad(player->angle));
}
