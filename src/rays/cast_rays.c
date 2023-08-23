#include <math.h>
#include "../../include/prototypes.h"

static void get_vertical_ray_pos(sfVector2f *ray_pos, float ray_angle, raycaster_t *raycaster, sfVector2f *next)
{
    float tan_value = tanf(deg_to_rad(ray_angle));

    raycaster->tries = 0;
    if (cosf(deg_to_rad(ray_angle)) > 0.001) {
        ray_pos->x = average_bitshift(raycaster->power_2.y, raycaster->block_size.y) + raycaster->block_size.y;
        ray_pos->y = (raycaster->player->pos.x - ray_pos->x) * tan_value + raycaster->player->pos.y;
        next->x = raycaster->block_size.y;
        next->y = -next->x * tan_value;
    } else if (cosf(deg_to_rad(ray_angle)) < -0.001) {
        ray_pos->x = average_bitshift(raycaster->power_2.y, raycaster->block_size.x) - 0.0001f;
        ray_pos->y = (raycaster->player->pos.x - ray_pos->x) * tan_value + raycaster->player->pos.y;
        next->x = -raycaster->block_size.y;
        next->y = -next->x * tan_value;
    } else {
        *ray_pos = raycaster->player->pos;
        raycaster->tries = raycaster->max_tries.y;
    }
}

static void get_horizontal_ray_pos(sfVector2f *ray_pos, float ray_angle, raycaster_t *raycaster, sfVector2f *next)
{
    float tan_value = 1.0f / tanf(deg_to_rad(ray_angle));

    raycaster->tries = 0;
    if (sinf(deg_to_rad(ray_angle)) > 0.001) {
        ray_pos->y = average_bitshift(raycaster->power_2.x, raycaster->player->pos.y) - 0.0001f;
        ray_pos->x = (raycaster->player->pos.y - ray_pos->y) * tan_value + raycaster->player->pos.x;
        next->y = -raycaster->block_size.x;
        next->x = -next->y * tan_value;
    } else if (sinf(deg_to_rad(ray_angle)) < -0.001) {
        ray_pos->y = average_bitshift(raycaster->power_2.x, raycaster->player->pos.y) + raycaster->block_size.x;
        ray_pos->x = (raycaster->player->pos.y - ray_pos->y) * tan_value + raycaster->player->pos.x;
        next->y = raycaster->block_size.x;
        next->x = -next->y * tan_value;
    } else {
        *ray_pos = raycaster->player->pos;
        raycaster->tries = raycaster->max_tries.x;
    }
}

static float check_horizontal_line(raycaster_t *raycaster, sfVector2f *ray_pos, float ray_angle)
{
    sfVector2f next = {0};
    sfVector2i m = {0};
    float distance = 1000000;
    unsigned int mp = 0;

    get_horizontal_ray_pos(ray_pos, ray_angle, raycaster, &next);
    while (raycaster->tries < raycaster->max_tries.x) {
        m.x = (int)(ray_pos->x) >> raycaster->power_2.x;
        m.y = (int)(ray_pos->y) >> raycaster->power_2.y;
        mp = m.y * raycaster->map_size.x + m.x;
        if (mp > 0 && mp < raycaster->map_surface && map[mp] == 1) {
            distance = calc_distance(&raycaster->player->pos, ray_pos, ray_angle);
            raycaster->tries = raycaster->max_tries.x;
        } else {
            ray_pos->x += next.x;
            ray_pos->y += next.y;
            raycaster->tries++;
        }
    }
    return (distance);
}

static float check_vertical_line(raycaster_t *raycaster, sfVector2f *ray_pos, float ray_angle)
{
    sfVector2f next = {0};
    sfVector2i m = {0};
    float distance = 1000000;
    unsigned int mp = 0;

    get_vertical_ray_pos(ray_pos, ray_angle, raycaster, &next);
    while (raycaster->tries < raycaster->max_tries.y) {
        m.x = (int)(ray_pos->x) >> raycaster->power_2.x;
        m.y = (int)(ray_pos->y) >> raycaster->power_2.y;
        mp = m.y * raycaster->map_size.y + m.x;
        if (mp > 0 && mp < raycaster->map_surface && map[mp] == 1) {
            distance = calc_distance(&raycaster->player->pos, ray_pos, ray_angle);
            raycaster->tries = raycaster->max_tries.y;
        } else {
            ray_pos->x += next.x;
            ray_pos->y += next.y;
            raycaster->tries++;
        }
    }
    return (distance);
}

static void create_3d_wall(float distance, unsigned int i, raycaster_t *raycaster, sfColor *color)
{
    sfVertex vertex = {0};
    float height = (float)(raycaster->map_surface * 540) / fabsf(distance);

    vertex.color = *color;
    vertex.position.x = raycaster->render_specs.wall_size.x * (float)i;
    vertex.position.y = ((float)raycaster->window_size.y / 2.0f) - (height / 2.0f);
    sfVertexArray_append(raycaster->walls_3d, vertex);
    vertex.color = *color;
    vertex.position.x = (raycaster->render_specs.wall_size.x * (float)i) + raycaster->render_specs.wall_size.x;
    vertex.position.y = ((float)raycaster->window_size.y / 2.0f) - (height / 2.0f);
    sfVertexArray_append(raycaster->walls_3d, vertex);
    vertex.color = *color;
    vertex.position.x = (raycaster->render_specs.wall_size.x * (float)i) + raycaster->render_specs.wall_size.x;
    vertex.position.y = ((float)raycaster->window_size.y / 2.0f) + (height / 2.0f);
    sfVertexArray_append(raycaster->walls_3d, vertex);
    vertex.color = *color;
    vertex.position.x = (raycaster->render_specs.wall_size.x * (float)i);
    vertex.position.y = ((float)raycaster->window_size.y / 2.0f) + (height / 2.0f);
    sfVertexArray_append(raycaster->walls_3d, vertex);
}

void cast_rays(raycaster_t *raycaster)
{
    float h_distance = 0;
    float v_distance = 0;
    sfVertex vertex = {0};
    sfVector2f h_pos = {0};
    sfVector2f v_pos = {0};
    float ray_dist = 0.01f;
    float ray_angle = (raycaster->player->angle - ((float)raycaster->rays_number / 2.0f) * ray_dist);
    float shortest_distance = 0;
    sfColor color = {0};

    sfVertexArray_clear(raycaster->rays_2d);
    sfVertexArray_clear(raycaster->walls_3d);
    for (unsigned int i = 0; i < raycaster->rays_number; i++) {
        h_distance = check_horizontal_line(raycaster, &h_pos, ray_angle);
        v_distance = check_vertical_line(raycaster, &v_pos, ray_angle);
        vertex.position = raycaster->player->pos;
        vertex.color = raycaster->render_specs.wall_colors[2];
        sfVertexArray_append(raycaster->rays_2d, vertex);
        vertex.position = (h_distance < v_distance) ? h_pos : v_pos;
        vertex.color = raycaster->render_specs.wall_colors[2];
        sfVertexArray_append(raycaster->rays_2d, vertex);
        ray_angle += raycaster->ray_shift;
        shortest_distance = (h_distance < v_distance) ? h_distance : v_distance;
        color = raycaster->render_specs.wall_colors[(h_distance < v_distance)];
        create_3d_wall(shortest_distance, i, raycaster, &color);
    }
}
