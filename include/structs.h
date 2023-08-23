#ifndef STRUCTS_H_
	#define STRUCTS_H_

static const int map[256] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

enum {
    MOUSE_VIEW = 0,
    PAUSE,
    OPTIONS_COUNT,
};

typedef struct {
    sfVector2f pos;
    sfVector2f delta;
    float angle;
    sfRectangleShape *object;
} player_t;

typedef struct {
    int number;
    int *elements;
} options_t;

typedef struct {
    sfColor *wall_colors;
    sfColor *map_colors;
    sfVector2f wall_size;
} render_specs_t;

typedef struct {
    unsigned int number;
    unsigned int tries;
    sfVector2u max_tries;
    sfVertexArray *rays_2d;
    sfVertexArray *walls_3d;
    float shift;
} rays_t;

typedef struct {
    sfVector2u size;
    unsigned int surface;
    sfRectangleShape **walls;
} map_t;

typedef struct {
    sfVector2u window_size;
    sfVector2f block_size;
    sfVector2u power_2;
    player_t *player;
    options_t *options;
    render_specs_t *render_specs;
    rays_t *rays;
    map_t *map;
} raycaster_t;

#endif /*STRUCTS_H_*/
