#include "../include/structs.h"
#include "../include/prototypes.h"

int main(void)
{
    sfEvent event = {0};
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    raycaster_t *raycaster = create_raycaster(&mode, 720);
    sfRenderWindow *window = sfRenderWindow_create(raycaster->mode, "Raycaster", sfDefaultStyle, NULL);
    sfClock *clock = sfClock_create();

    sfRenderWindow_setFramerateLimit(window, 60);
    raycaster->tries = 0;
    raycaster->max_tries = raycaster->map_size;
    while (sfRenderWindow_isOpen(window)) {
        raycaster->wall_size.x = (float)raycaster->mode.width / (float)raycaster->rays_nb;
        raycaster->wall_size.y = (float)raycaster->mode.height;
        sfRenderWindow_clear(window, sfBlack);
        if (sfClock_getElapsedTime(clock).microseconds > (62 * 1000)) {
            sfClock_restart(clock);
            move_2d_player(raycaster);
            cast_rays(raycaster);
            change_resolution(raycaster);
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
