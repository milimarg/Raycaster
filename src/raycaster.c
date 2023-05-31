#include <stdlib.h>
#include "../include/structs.h"
#include "../include/prototypes.h"

raycaster_t *create_raycaster(sfVideoMode *mode)
{
    raycaster_t *raycaster = malloc(sizeof(raycaster_t));

    raycaster->mode = *mode;
    create_2d_map(raycaster);
    raycaster->walls_3d = sfVertexArray_create();
    create_player(raycaster);
    return (raycaster);
}
