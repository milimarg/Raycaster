#ifndef PROTOTYPES_H_
	#define PROTOTYPES_H_

    // CREATE //

    raycaster_t *create_raycaster(sfVideoMode *mode);
    void create_2d_map(raycaster_t *raycaster);
    void create_player(raycaster_t *raycaster);

    // MOVE //

    void move_2d_player(raycaster_t *raycaster);

    // DISPLAY //

    void display_2d_map(raycaster_t *raycaster, sfRenderWindow *window);
    void display_3d_map(raycaster_t *raycaster, sfRenderWindow *window);

// RAYS //

    void cast_rays(raycaster_t *raycaster);

    // MATH TOOLS //

    float deg_to_rad(float angle);
    float calc_distance(sfVector2f *player, sfVector2f *ray, float ray_angle);
    float fix_angle(float angle);

#endif /*PROTOTYPES_H_*/
