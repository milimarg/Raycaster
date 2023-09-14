#include "../../include/prototypes.h"

void increase_resolution(raycaster_t *raycaster)
{
    static const unsigned int shift = 2;

    if (raycaster->rays->number * shift <= MAX_RAYS) {
        raycaster->rays->number *= shift;
        raycaster->rays->shift /= (float)shift;
        update_3d_wall_size(raycaster->render_specs, &raycaster->window_size,
        raycaster->rays->number);
    }
}

void decrease_resolution(raycaster_t *raycaster)
{
    static const unsigned int shift = 2;

    if (raycaster->rays->number / shift >= MIN_RAYS) {
        raycaster->rays->number /= shift;
        raycaster->rays->shift *= (float)shift;
        update_3d_wall_size(raycaster->render_specs, &raycaster->window_size,
        raycaster->rays->number);
    }
}
