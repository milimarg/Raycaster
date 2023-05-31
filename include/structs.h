#ifndef STRUCTS_H_
	#define STRUCTS_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

    #define MAP_WIDTH 8
    #define MAP_HEIGHT 8
    #define MAP_SURFACE MAP_WIDTH * MAP_HEIGHT
    static const int map[MAP_SURFACE] = {
            1, 1, 1, 1, 1, 1, 1, 1,
            1, 0, 0, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 0, 0, 0, 1,
            1, 0, 0, 1, 0, 0, 0, 1,
            1, 0, 0, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 1, 1, 1, 1, 1
    };

    typedef struct player_s {
        sfVector2f pos;
        sfVector2f delta;
        double angle;
        double move_offset;
        sfRectangleShape *object;
        sfRectangleShape *stick_object;
    } player_t;

    typedef struct raycaster_s {
        sfVideoMode mode;
        player_t *player;
        sfVector2f block_size;
        sfRectangleShape **blocks_2d;
        int rays_nb;
        int power_2;
        int tries;
        int max_tries;
        sfVertexArray *rays_2d;
        sfVertexArray *walls_3d;
        sfVector2f wall_size;
    } raycaster_t;

#endif /*STRUCTS_H_*/
