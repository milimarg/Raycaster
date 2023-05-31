#include <unistd.h>
#include "../include/structs.h"
#include "../include/prototypes.h"

int main(void)
{
    sfEvent event = {0};
    raycaster_t *raycaster = create_raycaster(&(sfVideoMode){1920, 1080, 32});
    sfRenderWindow *window = sfRenderWindow_create(raycaster->mode,
    "MyRaycaster", sfDefaultStyle, NULL);
    sfClock *clock = sfClock_create();

    sfRenderWindow_setFramerateLimit(window, 60);
    raycaster->rays_nb = 60;
    raycaster->power_2 = 6;
    raycaster->tries = 0;
    raycaster->max_tries = 8;
    raycaster->wall_size.x = (double)raycaster->mode.width / (double)raycaster->rays_nb;
    raycaster->wall_size.y = raycaster->mode.height;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        if (sfClock_getElapsedTime(clock).microseconds > (50 * 1000)) {
            move_2d_player(raycaster);
            cast_rays(raycaster);
            sfClock_restart(clock);
        }
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        display_3d_map(raycaster, window);
        display_2d_map(raycaster, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
