#ifndef PROTOTYPES_H_
	#define PROTOTYPES_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include "structs.h"

#define MIN_RAYS 45
#define MAX_RAYS 720

// CREATE //

raycaster_t *create_raycaster(sfRenderWindow *window, sfColor wall_colors[3],
sfVector2u map_size, sfColor map_colors[2]);
void create_2d_map(raycaster_t *raycaster);
void create_player(raycaster_t *raycaster);

// MOVE //

void controls_move(player_t *player, const sfVector2f *delta);
void controls_turn(player_t *player, float angle);
void update(raycaster_t *raycaster, sfRenderWindow *window);
void move_forward(raycaster_t *raycaster);
void move_backward(raycaster_t *raycaster);
void turn_left(raycaster_t *raycaster);
void turn_right(raycaster_t *raycaster);

// DISPLAY //

void display_2d_map(raycaster_t *raycaster, sfRenderWindow *window);
void display_3d_map(raycaster_t *raycaster, sfRenderWindow *window);

// RAYS //

void cast_rays(raycaster_t *raycaster);
void update_3d_wall_size(render_specs_t *render, sfVector2u *window_size,
unsigned int rays_number);

// MATH TOOLS //

float deg_to_rad(float angle);
float calc_distance(sfVector2f *player, sfVector2f *ray, float ray_angle);
float fix_angle(float angle);
int round_float(float n);
void invert_variable(int *a);
float average_bitshift(unsigned int power_2, float value);

// OPTIONS

void increase_resolution(raycaster_t *raycaster);
void decrease_resolution(raycaster_t *raycaster);
void mouse_view(sfRenderWindow *window, raycaster_t *raycaster);
void toggle_mouse_view(raycaster_t *raycaster);
void toggle_pause(raycaster_t *raycaster);
void increase_wall_height(raycaster_t *raycaster);
void decrease_wall_height(raycaster_t *raycaster);

#endif /*PROTOTYPES_H_*/
