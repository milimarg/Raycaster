#ifndef PROTOTYPES_H_
	#define PROTOTYPES_H_

// CREATE //

raycaster_t *create_raycaster(sfVideoMode *mode, unsigned int rays_number);
void create_2d_map(raycaster_t *raycaster);
void create_player(raycaster_t *raycaster);

// MOVE //

void move_2d_player(raycaster_t *raycaster);
void controls_move(player_t *player, const sfVector2f *delta);
void tank_controls_turn(player_t *player, float angle);

// DISPLAY //

void display_2d_map(raycaster_t *raycaster, sfRenderWindow *window);
void display_3d_map(raycaster_t *raycaster, sfRenderWindow *window);

// RAYS //

void cast_rays(raycaster_t *raycaster);
void change_resolution(raycaster_t *raycaster);

// MATH TOOLS //

float deg_to_rad(float angle);
float calc_distance(sfVector2f *player, sfVector2f *ray, float ray_angle);
float fix_angle(float angle);

#endif /*PROTOTYPES_H_*/
