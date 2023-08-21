#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/structs.h"
#include "../include/prototypes.h"

static int round_float(float n)
{
    return ((int)((n < 0) ? (n - 0.5) : (n + 0.5)));
}

static void set_power_2(raycaster_t *raycaster)
{
    float power_2_x = log2f(raycaster->block_size.x);
    float power_2_y = log2f(raycaster->block_size.y);

    if (ceilf(power_2_x) != power_2_x) {
        power_2_x = (float)round_float(power_2_x);
    }
    if (ceilf(power_2_y) != power_2_y) {
        power_2_y = (float)round_float(power_2_y);
    }
    raycaster->block_size = (sfVector2f){powf(2, power_2_x), powf(2, power_2_y)};
    raycaster->power_2 = (sfVector2u){(unsigned int)power_2_x, (unsigned int)power_2_y};
}

raycaster_t *create_raycaster(sfRenderWindow *window)
{
    raycaster_t *raycaster = malloc(sizeof(raycaster_t));
    sfVector2i center = {0};

    raycaster->window_size = sfRenderWindow_getSize(window);
    raycaster->map_size = (sfVector2u){16, 16};
    raycaster->map_surface = raycaster->map_size.x * raycaster->map_size.y;
    raycaster->rays_nb = 720;
    raycaster->tries = 0;
    raycaster->max_tries = raycaster->map_size;
    update_3d_wall_size(raycaster);
    create_2d_map(raycaster);
    raycaster->walls_3d = sfVertexArray_create();
    create_player(raycaster);
    set_power_2(raycaster);

    center.x = (int)((float)raycaster->window_size.x / 2.0f);
    center.y = (int)((float)raycaster->window_size.y / 2.0f);
    printf("size => x = %d & y = %d\n", raycaster->window_size.x, raycaster->window_size.y);
    printf("center => x = %d & y = %d\n", center.x, center.y);
    sfMouse_setPositionRenderWindow(center, window);

    return (raycaster);
}
