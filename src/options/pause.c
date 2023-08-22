#include "../../include/prototypes.h"

void toggle_pause(raycaster_t *raycaster)
{
    invert_variable(&raycaster->options.elements[PAUSE]);
}
