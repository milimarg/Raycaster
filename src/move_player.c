#include "../include/structs.h"
#include "../include/prototypes.h"

static void move_up(raycaster_t *raycaster)
{
    sfRectangleShape_move(raycaster->player->object, (sfVector2f){0, -raycaster->player->move_offset});
    raycaster->player->pos.y -= raycaster->player->move_offset;
}

static void move_down(raycaster_t *raycaster)
{
    sfRectangleShape_move(raycaster->player->object, (sfVector2f){0, raycaster->player->move_offset});
    raycaster->player->pos.y += raycaster->player->move_offset;
}

static void move_left(raycaster_t *raycaster)
{
    sfRectangleShape_move(raycaster->player->object, (sfVector2f){-raycaster->player->move_offset, 0});
    raycaster->player->pos.x -= raycaster->player->move_offset;
}

static void move_right(raycaster_t *raycaster)
{
    sfRectangleShape_move(raycaster->player->object, (sfVector2f){raycaster->player->move_offset, 0});
    raycaster->player->pos.x += raycaster->player->move_offset;
}

void move_2d_player(raycaster_t *raycaster)
{
    sfKeyCode keys[] = {sfKeyUp, sfKeyDown, sfKeyLeft, sfKeyRight, -1};
    void (*moves[])(raycaster_t *t) = {&move_up, &move_down, &move_left, &move_right};

    for (int i = 0; keys[i] != -1; i++) {
        if (sfKeyboard_isKeyPressed(keys[i])) {
            moves[i](raycaster);
            return;
        }
    }
}
