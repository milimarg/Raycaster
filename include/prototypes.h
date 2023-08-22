#ifndef PROTOTYPES_H_
	#define PROTOTYPES_H_
    #include "structs.h"

// CREATE //

raycaster_t *create_raycaster(sfRenderWindow *window, sfColor colors[2], sfVector2u map_size);
void create_2d_map(raycaster_t *raycaster);
void create_player(raycaster_t *raycaster);

// MOVE //

void move_2d_player(raycaster_t *raycaster);
void controls_move(player_t *player, const sfVector2f *delta);
void tank_controls_turn(player_t *player, float angle);
void update(raycaster_t *raycaster, sfRenderWindow *window);

// DISPLAY //

void display_2d_map(raycaster_t *raycaster, sfRenderWindow *window);
void display_3d_map(raycaster_t *raycaster, sfRenderWindow *window);

// RAYS //

void cast_rays(raycaster_t *raycaster);
void update_3d_wall_size(raycaster_t *raycaster);

// MATH TOOLS //

float deg_to_rad(float angle);
float calc_distance(sfVector2f *player, sfVector2f *ray, float ray_angle);
float fix_angle(float angle);
int round_float(float n);
void invert_variable(int *a);

// OPTIONS

void increase_resolution(raycaster_t *raycaster);
void decrease_resolution(raycaster_t *raycaster);
void mouse_view(sfRenderWindow *window, raycaster_t *raycaster);
void toggle_mouse_view(raycaster_t *raycaster);
void pause(raycaster_t *raycaster);
void toggle_pause(raycaster_t *raycaster);

#endif /*PROTOTYPES_H_*/
