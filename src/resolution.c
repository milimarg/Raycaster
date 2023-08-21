#include "../include/structs.h"
#include "../include/prototypes.h"

static void update_resolution(int state_is_up, raycaster_t *raycaster)
{
    static const int shift = 2;

    if (state_is_up && (raycaster->rays_nb * shift) <= 720) {
        raycaster->rays_nb *= shift;
        raycaster->ray_shift /= (float)shift;
    }
    if (!state_is_up && (raycaster->rays_nb / shift) >= 45) {
        raycaster->rays_nb /= shift;
        raycaster->ray_shift *= (float)shift;
    }
    update_3d_wall_size(raycaster);
}

void change_resolution(raycaster_t *raycaster)
{
    static const sfKeyCode values[] = {sfKeyComma, sfKeyPeriod, -1};
    static int anti_spam[2] = {0};

    for (int i = 0; values[i] != -1; i++) {
        if (sfKeyboard_isKeyPressed(values[i]) && !anti_spam[i]) {
            anti_spam[i] = 1;
            update_resolution(i == 0, raycaster);
        }
        if (!sfKeyboard_isKeyPressed(values[i]) && anti_spam[i]) {
            anti_spam[i] = 0;
        }
    }
}
