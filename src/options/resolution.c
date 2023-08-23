#include "../../include/prototypes.h"

void increase_resolution(raycaster_t *raycaster)
{
    static const int shift = 2;

    if (raycaster->rays_number * shift <= 720) {
        raycaster->rays_number *= shift;
        raycaster->ray_shift /= (float)shift;
        update_3d_wall_size(&raycaster->render_specs, &raycaster->window_size,
        raycaster->rays_number);
    }
}

void decrease_resolution(raycaster_t *raycaster)
{
    static const int shift = 2;

    if (raycaster->rays_number / shift >= 45) {
        raycaster->rays_number /= shift;
        raycaster->ray_shift *= (float)shift;
        update_3d_wall_size(&raycaster->render_specs, &raycaster->window_size,
        raycaster->rays_number);
    }
}
