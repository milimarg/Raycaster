#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "../include/structs.h"
#include "../include/prototypes.h"

static int round_float(float n)
{
    return ((n < 0) ? (n - 0.5) : (n + 0.5));
}

static void set_power_2(raycaster_t *raycaster)
{
    double power_2_x = log2(raycaster->block_size.x);
    double power_2_y = log2(raycaster->block_size.y);

    if (ceil(power_2_x) != power_2_x)
        power_2_x = round_float(power_2_x);
    if (ceil(power_2_y) != power_2_y)
        power_2_y = round_float(power_2_y);
    raycaster->block_size = (sfVector2f){pow(2, power_2_x), pow(2, power_2_y)};
    raycaster->power_2 = (sfVector2u){power_2_x, power_2_y};
}

int main(void)
{
    sfEvent event = {0};
    raycaster_t *raycaster = create_raycaster(&(sfVideoMode){1920, 1080, 32});
    sfRenderWindow *window = sfRenderWindow_create(raycaster->mode,
    "MyRaycaster", sfDefaultStyle, NULL);
    sfClock *clock = sfClock_create();

    sfRenderWindow_setFramerateLimit(window, 60);
    set_power_2(raycaster);
    raycaster->rays_nb = 720;
    raycaster->tries = 0;
    raycaster->max_tries = raycaster->map_size;
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
