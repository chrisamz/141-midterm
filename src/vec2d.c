#include "vec2d.h"

#include <stdio.h>
#include <math.h>

float norm_vec2d(vec2d v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

void print_vec2d(vec2d v) {
    printf("(%f, %f)\n", v.x, v.y);
}