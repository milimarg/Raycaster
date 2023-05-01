#ifndef STRUCTS_H_
	#define STRUCTS_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

    typedef struct player_s {
        sfVector2f pos;
        double angle;
        sfRectangleShape *object;
        double move_offset;
    } player_t;

    typedef struct raycaster_s {
        player_t *player;
        sfVector2f block_size;
        sfRectangleShape **blocks_2d;
    } raycaster_t;

#endif /*STRUCTS_H_*/
