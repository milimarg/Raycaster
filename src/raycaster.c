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
    raycaster->block_size.x = powf(2, power_2_x);
    raycaster->block_size.y = powf(2, power_2_y);
    raycaster->power_2.x = (unsigned int)power_2_x;
    raycaster->power_2.y = (unsigned int)power_2_y;
}

static void set_display_options(options_t *display)
{
    display->number = OPTIONS_COUNT;
    display->elements = malloc(sizeof(int) * display->number);
    for (int i = 0; i < display->number; i++) {
        display->elements[i] = 1;
    }
}

static void set_values(raycaster_t *raycaster, sfRenderWindow *window,
sfVector2u map_size)
{
    raycaster->window_size = sfRenderWindow_getSize(window);
    raycaster->map = malloc(sizeof(map_t));
    raycaster->map->size = map_size;
    raycaster->map->surface = raycaster->map->size.x * raycaster->map->size.y;
    raycaster->rays = malloc(sizeof(rays_t));
    raycaster->rays->number = 720;
    raycaster->rays->tries = 0;
    raycaster->rays->max_tries = raycaster->map->size;
    raycaster->rays->walls_3d = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(raycaster->rays->walls_3d, sfQuads);
}

raycaster_t *create_raycaster(sfRenderWindow *window, sfColor wall_colors[3],
sfVector2u map_size, sfColor map_colors[2])
{
    raycaster_t *raycaster = malloc(sizeof(raycaster_t));

    set_values(raycaster, window, map_size);
    raycaster->render_specs = malloc(sizeof(render_specs_t));
    raycaster->render_specs->wall_colors = malloc(sizeof(sfColor) * 3);
    raycaster->render_specs->map_colors = malloc(sizeof(sfColor) * 2);
    for (int i = 0; i < 2; i++) {
        raycaster->render_specs->wall_colors[i] = wall_colors[i];
        raycaster->render_specs->map_colors[i] = map_colors[i];
    }
    raycaster->render_specs->wall_colors[2] = wall_colors[2];
    raycaster->options = malloc(sizeof(options_t));
    update_3d_wall_size(raycaster->render_specs, &raycaster->window_size,
    raycaster->rays->number);
    create_2d_map(raycaster);
    create_player(raycaster);
    set_power_2(raycaster);
    set_display_options(raycaster->options);
    return (raycaster);
}
