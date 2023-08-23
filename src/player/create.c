#include <stdlib.h>
#include "../../include/prototypes.h"

static void init_player_object(player_t *player, sfVector2f *block_size)
{
    sfVector2f half_block_size = {block_size->x / 4.0f, block_size->y / 4.0f};
    sfVector2f origin = {half_block_size.x / 4.0f, half_block_size.y / 4.0f};

    player->object = sfRectangleShape_create();
    sfRectangleShape_setPosition(player->object, player->pos);
    sfRectangleShape_setSize(player->object, half_block_size);
    sfRectangleShape_setOrigin(player->object, origin);
    sfRectangleShape_setFillColor(player->object, sfYellow);
    sfRectangleShape_setOutlineThickness(player->object, 0);
}

void create_player(raycaster_t *raycaster)
{
    raycaster->player = malloc(sizeof(player_t));
    raycaster->player->pos = (sfVector2f){50, 50};
    raycaster->player->angle = 0;
    raycaster->rays->shift = 0.125f;
    raycaster->rays->rays_2d = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(raycaster->rays->rays_2d, sfLines);
    init_player_object(raycaster->player, &raycaster->block_size);
}
