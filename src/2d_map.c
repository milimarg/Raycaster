#include <stdlib.h>
#include "../include/structs.h"
#include "../include/prototypes.h"

void create_2d_map(raycaster_t *raycaster)
{
    int k = 0;
    sfColor colors[2] = {sfBlack, sfWhite};
    sfVector2f pos = {0};

    raycaster->block_size = (sfVector2f){32, 32};
    raycaster->blocks_2d = malloc(sizeof(sfRectangleShape *) * (raycaster->map_surface + 1));
    for (unsigned int i = 0; i < raycaster->map_size.y; i++) {
        for (unsigned int j = 0; j < raycaster->map_size.x; j++) {
            raycaster->blocks_2d[k] = sfRectangleShape_create();
            pos.x = (float)(j * raycaster->map_surface) / ((float)raycaster->map_surface / raycaster->block_size.x);
            pos.y = (float)(i * raycaster->map_surface) / ((float)raycaster->map_surface / raycaster->block_size.y);
            sfRectangleShape_setPosition(raycaster->blocks_2d[k], pos);
            sfRectangleShape_setSize(raycaster->blocks_2d[k], raycaster->block_size);
            sfRectangleShape_setFillColor(raycaster->blocks_2d[k], colors[map[k]]);
            sfRectangleShape_setOutlineThickness(raycaster->blocks_2d[k], 0);
            k++;
        }
    }
    raycaster->blocks_2d[k] = NULL;
}

void display_2d_map(raycaster_t *raycaster, sfRenderWindow *window)
{
    for (int i = 0; raycaster->blocks_2d[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(window, raycaster->blocks_2d[i], NULL);
    }
    sfRenderWindow_drawVertexArray(window, raycaster->rays_2d, NULL);
    sfRenderWindow_drawRectangleShape(window, raycaster->player->object, NULL);
}
