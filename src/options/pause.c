#include "../../include/prototypes.h"

void pause(raycaster_t *raycaster)
{
    if (!raycaster->options.elements[PAUSE]) {
        return;
    }

}

void toggle_pause(raycaster_t *raycaster)
{
    invert_variable(&raycaster->options.elements[MOUSE_VIEW]);
}
