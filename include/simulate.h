#include "vec2d.h"
#include "vec3d.h"

void leapfrog1(vec2d* p, vec2d* v, vec2d* a, float step);
void leapfrog2(vec3d* p1, vec3d* v1, vec3d* p2, struct vec3d* v2, float m1, float m2, float step);
void leapfrog3(vec3d* p1, vec3d* v1, vec3d* p2, struct vec3d* v2, float m1, float m2, float r1, float r2, float step);