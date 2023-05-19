#ifndef VEC3D_H
#define VEC3D_H

struct vec3d {
    float x;
    float y;
    float z;
};

typedef struct vec3d vec3d;

float norm_vec3d(vec3d v);
void print_vec3d(vec3d v);

#endif // VEC3D_H