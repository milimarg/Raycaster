#include "../include/structs.h"
#include "../include/prototypes.h"

void display_3d_map(raycaster_t *raycaster, sfRenderWindow *window)
{
    sfRenderWindow_drawVertexArray(window, raycaster->walls_3d, NULL);
}
