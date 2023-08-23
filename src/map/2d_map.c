#include <stdlib.h>
#include "../../include/prototypes.h"

void create_2d_map(raycaster_t *raycaster)
{
    int k = 0;
    sfVector2f pos = {0};
    sfVector2f ratio = {0};
    sfColor color = {0};

    raycaster->block_size = (sfVector2f){32, 32};
    raycaster->map->walls = malloc(sizeof(sfRectangleShape *) * (raycaster->map->surface + 1));
    for (unsigned int i = 0; i < raycaster->map->size.y; i++) {
        for (unsigned int j = 0; j < raycaster->map->size.x; j++) {
            raycaster->map->walls[k] = sfRectangleShape_create();
            ratio.x = (float)raycaster->map->surface / raycaster->block_size.x;
            ratio.y = (float)raycaster->map->surface / raycaster->block_size.y;
            pos.x = (float)(j * raycaster->map->surface) / ratio.x;
            pos.y = (float)(i * raycaster->map->surface) / ratio.y;
            sfRectangleShape_setPosition(raycaster->map->walls[k], pos);
            sfRectangleShape_setSize(raycaster->map->walls[k], raycaster->block_size);
            color = raycaster->render_specs->map_colors[map[k]];
            sfRectangleShape_setFillColor(raycaster->map->walls[k], color);
            sfRectangleShape_setOutlineThickness(raycaster->map->walls[k], 0);
            k++;
        }
    }
    raycaster->map->walls[k] = NULL;
}

void display_2d_map(raycaster_t *raycaster, sfRenderWindow *window)
{
    for (int i = 0; raycaster->map->walls[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(window, raycaster->map->walls[i], NULL);
    }
    sfRenderWindow_drawVertexArray(window, raycaster->rays->rays_2d, NULL);
    sfRenderWindow_drawRectangleShape(window, raycaster->player->object, NULL);
}
