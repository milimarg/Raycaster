#include <math.h>
#include "../../include/prototypes.h"

float calc_distance(sfVector2f *player, sfVector2f *ray, float ray_angle)
{
    sfVector2f dist = {0};

    dist.x = cosf(deg_to_rad(ray_angle)) * (ray->x - player->x);
    dist.y = sinf(deg_to_rad(ray_angle)) * (ray->y - player->y);
    return (dist.x - dist.y);
}

int round_float(float n)
{
    return ((int)((n < 0) ? (n - 0.5) : (n + 0.5)));
}

void invert_variable(int *a)
{
    *a = !*a;
}

float average_bitshift(unsigned int power_2, float value)
{
    return (float)(((int)value >> power_2) << power_2);
}
