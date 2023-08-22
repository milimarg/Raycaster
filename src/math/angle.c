#include <math.h>
#include "../../include/prototypes.h"

float deg_to_rad(float angle)
{
    return (float)(angle * M_PI / 180.0);
}

float fix_angle(float angle)
{
    if (angle < 0) {
        angle += 360;
    }
    if (angle > 359) {
        angle -= 360;
    }
    return (angle);
}
