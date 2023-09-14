#include "../../include/prototypes.h"

void increase_wall_height(raycaster_t *raycaster)
{
    static const unsigned int shift = 50;

    if (raycaster->rays->wall_height_constant > ((float)raycaster->window_size.y / 2.0f)) {
        return;
    }
    raycaster->rays->wall_height_constant += shift;
}

void decrease_wall_height(raycaster_t *raycaster)
{
    static const unsigned int shift = 50;

    if (raycaster->rays->wall_height_constant <= shift) {
        return;
    }
    raycaster->rays->wall_height_constant -= shift;
}
