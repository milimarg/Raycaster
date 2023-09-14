#include "include/prototypes.h"

// map_size and block_size must be a power_2

int main(void)
{
    sfEvent event = {0};
    sfColor wall_colors[] = {sfWhite, sfBlue, sfYellow};
    sfColor map_colors[] = {sfBlack, sfWhite};
    sfVector2u map_size = {16, 16};
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfRenderWindow *window = sfRenderWindow_create(mode, "Raycaster", sfDefaultStyle, NULL);
    raycaster_t *raycaster = create_raycaster(window, wall_colors, map_size, map_colors);
    sfClock *clock = sfClock_create();

    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        if (sfClock_getElapsedTime(clock).microseconds > (62 * 1000)) {
            sfClock_restart(clock);
            update(raycaster, window);
        }
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
                sfRenderWindow_close(window);
            }
        }
        display_3d_map(raycaster, window);
        display_2d_map(raycaster, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
