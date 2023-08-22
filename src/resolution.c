#include "../include/prototypes.h"

void increase_resolution(raycaster_t *raycaster)
{
    static const int shift = 2;

    if (raycaster->rays_nb * shift <= 720) {
        raycaster->rays_nb *= shift;
        raycaster->ray_shift /= (float)shift;
        update_3d_wall_size(raycaster);
    }
}

void decrease_resolution(raycaster_t *raycaster)
{
    static const int shift = 2;

    if (raycaster->rays_nb / shift >= 45) {
        raycaster->rays_nb /= shift;
        raycaster->ray_shift *= (float)shift;
        update_3d_wall_size(raycaster);
    }
}
