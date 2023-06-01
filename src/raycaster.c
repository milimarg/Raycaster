#include <stdlib.h>
#include "../include/structs.h"
#include "../include/prototypes.h"

raycaster_t *create_raycaster(sfVideoMode *mode)
{
    raycaster_t *raycaster = malloc(sizeof(raycaster_t));

    raycaster->mode = *mode;
    raycaster->map_size = (sfVector2u){16, 16};
    raycaster->map_surface = raycaster->map_size.x * raycaster->map_size.y;
    create_2d_map(raycaster);
    raycaster->walls_3d = sfVertexArray_create();
    create_player(raycaster);
    return (raycaster);
}
