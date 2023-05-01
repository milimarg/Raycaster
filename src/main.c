#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/structs.h"
#include "../include/prototypes.h"

int main(void)
{
    sfEvent event = {0};
    raycaster_t *raycaster = create_raycaster();
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){800, 600, 32}, "MyRayCaster", sfDefaultStyle, NULL);
    sfClock *clock = sfClock_create();
    sfInt64 clock_time = 0;
    sfInt64 current_time = 0;

    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        clock_time = sfClock_getElapsedTime(clock).microseconds / 1000;
        if (clock_time - current_time > (100)) {
            current_time = clock_time;
            move_2d_player(raycaster);
        }
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        display_2d_map(raycaster, window);
        sfRenderWindow_drawRectangleShape(window, raycaster->player->object, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
