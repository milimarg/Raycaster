#include <stdlib.h>
#include "../include/structs.h"
#include "../include/prototypes.h"

void create_player(raycaster_t *raycaster)
{
    raycaster->player = malloc(sizeof(player_t));
    raycaster->player->pos = (sfVector2f){0, 0};
    raycaster->player->angle = 0;
    raycaster->player->move_offset = 1;
    raycaster->player->object = sfRectangleShape_create();
    sfRectangleShape_setPosition(raycaster->player->object, (sfVector2f){10, 10});
    sfRectangleShape_setSize(raycaster->player->object,
    (sfVector2f){raycaster->block_size.x / 2, raycaster->block_size.y / 2});
    sfRectangleShape_setFillColor(raycaster->player->object, sfYellow);
    sfRectangleShape_setOutlineThickness(raycaster->player->object, 0);
}
