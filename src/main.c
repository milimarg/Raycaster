#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "../include/structs.h"
#include "../include/prototypes.h"

static int round_float(float n)
{
    return ((int)((n < 0) ? (n - 0.5) : (n + 0.5)));
}

static void set_power_2(raycaster_t *raycaster)
{
    float power_2_x = log2f(raycaster->block_size.x);
    float power_2_y = log2f(raycaster->block_size.y);

    if (ceilf(power_2_x) != power_2_x)
        power_2_x = (float)round_float(power_2_x);
    if (ceilf(power_2_y) != power_2_y)
        power_2_y = (float)round_float(power_2_y);
    raycaster->block_size = (sfVector2f){powf(2, power_2_x), powf(2, power_2_y)};
    raycaster->power_2 = (sfVector2u){(unsigned int)power_2_x, (unsigned int)power_2_y};
}

int main(void)
{
    sfEvent event = {0};
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    raycaster_t *raycaster = create_raycaster(&mode);
    sfRenderWindow *window = sfRenderWindow_create(raycaster->mode, "Raycaster", sfDefaultStyle, NULL);
    sfClock *clock = sfClock_create();

    sfRenderWindow_setFramerateLimit(window, 60);
    set_power_2(raycaster);
    raycaster->rays_nb = 720;
    raycaster->tries = 0;
    raycaster->max_tries = raycaster->map_size;
    raycaster->wall_size.x = (float)raycaster->mode.width / (double)raycaster->rays_nb;
    raycaster->wall_size.y = raycaster->mode.height;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        if (sfClock_getElapsedTime(clock).microseconds > (50 * 1000)) {
            move_2d_player(raycaster);
            cast_rays(raycaster);
             // detect key to toggle controls
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
