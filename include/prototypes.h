#ifndef PROTOTYPES_H_
	#define PROTOTYPES_H_

    // CREATE //

    raycaster_t *create_raycaster(void);
    void create_2d_map(raycaster_t *raycaster);
    void create_player(raycaster_t *raycaster);

    // MOVE //

    void move_2d_player(raycaster_t *raycaster);

    // DISPLAY //

    void display_2d_map(raycaster_t *raycaster, sfRenderWindow *window);

#endif /*PROTOTYPES_H_*/
