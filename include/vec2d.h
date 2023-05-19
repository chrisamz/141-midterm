#ifndef VEC2D_H
#define VEC2D_H

struct vec2d {
    float x;
    float y;
};

typedef struct vec2d vec2d;

float norm_vec2d(vec2d v);
void print_vec2d(vec2d v);

#endif // VEC2D_H