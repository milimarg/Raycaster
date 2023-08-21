#include "../include/structs.h"
#include "../include/prototypes.h"

void update_3d_wall_size(raycaster_t *raycaster)
{
    raycaster->wall_size.x = (float)raycaster->window_size.x / (float)raycaster->rays_nb;
    raycaster->wall_size.y = (float)raycaster->window_size.y;
}

void display_3d_map(raycaster_t *raycaster, sfRenderWindow *window)
{
    sfRenderWindow_drawVertexArray(window, raycaster->walls_3d, NULL);
}
