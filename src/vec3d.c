#include "vec3d.h"

#include <stdio.h>
#include <math.h>

float norm_vec3d(vec3d v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

void print_vec3d(vec3d v)
{
    printf("(%f, %f, %f)\n", v.x, v.y, v.z);
}