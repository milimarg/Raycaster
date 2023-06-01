/*
** EPITECH PROJECT, 2023
** MyRaycaster
** File description:
** math_tools.c
*/

#include <math.h>
#include "../include/structs.h"

float deg_to_rad(float angle)
{
    return (angle * M_PI / 180.0);
}

float calc_distance(sfVector2f *player, sfVector2f *ray, float ray_angle)
{
    sfVector2f dist = {0};

    dist.x = cos(deg_to_rad(ray_angle)) * (ray->x - player->x);
    dist.y = sin(deg_to_rad(ray_angle)) * (ray->y - player->y);
    return (dist.x - dist.y );
}

float fix_angle(float angle)
{
    if (angle < 0)
        angle += 360;
    if (angle > (359))
        angle -= 360;
    return (angle);
}
