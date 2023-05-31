#include <stdlib.h>
#include "../../include/structs.h"
#include "../../include/prototypes.h"

static void init_player_object(player_t *player, sfVector2f *block_size)
{
    sfVector2f half_block_size = {block_size->x / 4.0, block_size->y / 4.0};
    sfVector2f origin = {half_block_size.x / 4.0, half_block_size.y / 4.0};

    player->object = sfRectangleShape_create();
    sfRectangleShape_setPosition(player->object, player->pos);
    sfRectangleShape_setSize(player->object, half_block_size);
    sfRectangleShape_setOrigin(player->object, origin);
    sfRectangleShape_setFillColor(player->object, sfYellow);
    sfRectangleShape_setOutlineThickness(player->object, 0);
}

static void init_player_stick_object(player_t *player, sfVector2f *block_size)
{
    sfVector2f stick_size = {block_size->x / 2.0, block_size->y / 16.0};
    sfVector2f origin = {0, stick_size.y / 16.0};

    player->stick_object = sfRectangleShape_create();
    sfRectangleShape_setPosition(player->stick_object, player->pos);
    sfRectangleShape_setSize(player->stick_object, stick_size);
    sfRectangleShape_setOrigin(player->stick_object, origin);
    sfRectangleShape_setFillColor(player->stick_object, sfYellow);
    sfRectangleShape_setOutlineThickness(player->object, 0);
}

void create_player(raycaster_t *raycaster)
{
    raycaster->player = malloc(sizeof(player_t));
    raycaster->player->pos = (sfVector2f){100, 100};
    raycaster->player->angle = 0;
    raycaster->player->move_offset = 1;
    raycaster->rays_2d = sfVertexArray_create();
    init_player_object(raycaster->player, &raycaster->block_size);
    init_player_stick_object(raycaster->player, &raycaster->block_size);
}
