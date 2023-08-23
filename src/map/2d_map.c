#include <stdlib.h>
#include "../../include/prototypes.h"

void create_2d_map(raycaster_t *raycaster)
{
    int k = 0;
    sfVector2f pos = {0};
    sfVector2f ratio = {0};
    sfColor color = {0};

    raycaster->block_size = (sfVector2f){32, 32};
    raycaster->blocks_2d = malloc(sizeof(sfRectangleShape *) * (raycaster->map_surface + 1));
    for (unsigned int i = 0; i < raycaster->map_size.y; i++) {
        for (unsigned int j = 0; j < raycaster->map_size.x; j++) {
            raycaster->blocks_2d[k] = sfRectangleShape_create();
            ratio.x = (float)raycaster->map_surface / raycaster->block_size.x;
            ratio.y = (float)raycaster->map_surface / raycaster->block_size.y;
            pos.x = (float)(j * raycaster->map_surface) / ratio.x;
            pos.y = (float)(i * raycaster->map_surface) / ratio.y;
            sfRectangleShape_setPosition(raycaster->blocks_2d[k], pos);
            sfRectangleShape_setSize(raycaster->blocks_2d[k], raycaster->block_size);
            color = raycaster->render_specs.map_colors[map[k]];
            sfRectangleShape_setFillColor(raycaster->blocks_2d[k], color);
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
