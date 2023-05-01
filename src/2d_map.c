#include <stdlib.h>
#include "../include/structs.h"
#include "../include/prototypes.h"

int blocks_nb = 64;
int width = 8;
sfVector2u map_size = {8, 8};
sfVector2f block_size = {8, 8};
int map[8][8] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
};

void create_2d_map(raycaster_t *raycaster)
{
    sfColor colors[2] = {sfBlack, sfWhite};
    sfVector2f pos = {0};
    int k = 0;

    raycaster->block_size = (sfVector2f){8, 8};
    raycaster->blocks_2d = malloc(sizeof(sfRectangleShape *) * (blocks_nb + 1));
    for (unsigned int i = 0; i < map_size.y; i++) {
        for (unsigned int j = 0; j < map_size.x; j++) {
            raycaster->blocks_2d[k] = sfRectangleShape_create();
            pos = (sfVector2f){j * block_size.x, i * block_size.y};
            sfRectangleShape_setPosition(raycaster->blocks_2d[k], pos);
            sfRectangleShape_setSize(raycaster->blocks_2d[k], raycaster->block_size);
            sfRectangleShape_setFillColor(raycaster->blocks_2d[k], colors[map[i][j]]);
            sfRectangleShape_setOutlineThickness(raycaster->blocks_2d[k], 0);
            k++;
        }
    }
    raycaster->blocks_2d[k] = NULL;
}

void display_2d_map(raycaster_t *raycaster, sfRenderWindow *window)
{
    for (int i = 0; raycaster->blocks_2d[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(window, raycaster->blocks_2d[i],
        NULL);
    }
}
