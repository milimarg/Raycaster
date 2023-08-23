#include "../../include/prototypes.h"

void update_3d_wall_size(render_specs_t *render, sfVector2u *window_size,
unsigned int rays_number)
{
    render->wall_size.x = (float)window_size->x / (float)rays_number;
    render->wall_size.y = (float)window_size->y;
}

void display_3d_map(raycaster_t *raycaster, sfRenderWindow *window)
{
    sfRenderWindow_drawVertexArray(window, raycaster->rays->walls_3d, NULL);
}
