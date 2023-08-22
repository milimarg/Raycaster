#include <stdlib.h>
#include <math.h>
#include "../include/prototypes.h"

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

static void set_display_options(options_t *display)
{
    display->number = OPTIONS_COUNT;
    display->elements = malloc(sizeof(int) * display->number);
    for (int i = 0; i < display->number; i++) {
        display->elements[i] = 1;
    }
}

raycaster_t *create_raycaster(sfRenderWindow *window, sfColor colors[2], sfVector2u map_size)
{
    raycaster_t *raycaster = malloc(sizeof(raycaster_t));

    raycaster->window_size = sfRenderWindow_getSize(window);
    raycaster->map_size = map_size;
    raycaster->map_surface = raycaster->map_size.x * raycaster->map_size.y;
    raycaster->rays_nb = 720;
    raycaster->tries = 0;
    raycaster->max_tries = raycaster->map_size;
    raycaster->walls_3d = sfVertexArray_create();
    raycaster->render_specs.primary = colors[0];
    raycaster->render_specs.second = colors[1];
    update_3d_wall_size(raycaster);
    create_2d_map(raycaster);
    create_player(raycaster);
    set_power_2(raycaster);
    set_display_options(&raycaster->options);
    return (raycaster);
}
