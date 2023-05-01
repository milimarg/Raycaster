#include <stdlib.h>
#include "../include/structs.h"
#include "../include/prototypes.h"

raycaster_t *create_raycaster(void)
{
    raycaster_t *raycaster = malloc(sizeof(raycaster_t));

    create_2d_map(raycaster);
    create_player(raycaster);
    return (raycaster);
}
