#include "simulate.h"

#include <math.h>

void leapfrog1(vec2d* p, vec2d* v, vec2d* a, float s)
{
    (*p).x += (*v).x * s + 0.5 * (*a).x * s * s;
    (*p).y += (*v).y * s + 0.5 * (*a).y * s * s;
    (*v).x += 0.5 * (*a).x * s;
    (*v).y += 0.5 * (*a).y * s;
}

void leapfrog2(vec3d* p1, vec3d* v1, vec3d* p2, vec3d* v2, float m1, float m2, float step) {
    vec3d p = {(*p2).x - (*p1).x, (*p2).y - (*p1).y, (*p2).z - (*p1).z};
    float r = norm_vec3d(p);
    float c = m1 * m2 / (r * r * r);
    vec3d F = {p.x * c, p.y * c, p.z * c};

    (*v1).x += F.x * step / (2 * m1);
    (*v1).y += F.y * step / (2 * m1);
    (*v1).z += F.z * step / (2 * m1);

    (*v2).x -= F.x * step / (2 * m2);
    (*v2).y -= F.y * step / (2 * m2);
    (*v2).z -= F.z * step / (2 * m2);

    (*p1).x += (*v1).x * step;
    (*p1).y += (*v1).y * step;
    (*p1).z += (*v1).z * step;

    (*p2).x += (*v2).x * step;
    (*p2).y += (*v2).y * step;
    (*p2).z += (*v2).z * step;

    p = (vec3d){(*p2).x - (*p1).x, (*p2).y - (*p1).y, (*p2).z - (*p1).z};
    r = norm_vec3d(p);
    F = (vec3d){p.x * c, p.y * c, p.z * c};

    (*v1).x += F.x * step / (2 * m1);
    (*v1).y += F.y * step / (2 * m1);
    (*v1).z += F.z * step / (2 * m1);

    (*v2).x -= F.x * step / (2 * m2);
    (*v2).y -= F.y * step / (2 * m2);
    (*v2).z -= F.z * step / (2 * m2);
}

void leapfrog3(vec3d* p1, vec3d* v1, vec3d* p2, struct vec3d* v2, float m1, float m2, float r1, float r2, float step)
{
    vec3d p = {(*p2).x - (*p1).x, (*p2).y - (*p1).y, (*p2).z - (*p1).z};
    float r = norm_vec3d(p);
    float c = m1 * m2 / pow((r * r + (r1 + r2) * (r1 + r2)), 1.5);
    vec3d F = {p.x * c, p.y * c, p.z * c};

    (*v1).x += F.x * step / (2 * m1);
    (*v1).y += F.y * step / (2 * m1);
    (*v1).z += F.z * step / (2 * m1);

    (*v2).x -= F.x * step / (2 * m2);
    (*v2).y -= F.y * step / (2 * m2);
    (*v2).z -= F.z * step / (2 * m2);

    (*p1).x += (*v1).x * step;
    (*p1).y += (*v1).y * step;
    (*p1).z += (*v1).z * step;

    (*p2).x += (*v2).x * step;
    (*p2).y += (*v2).y * step;
    (*p2).z += (*v2).z * step;

    p = (vec3d){(*p2).x - (*p1).x, (*p2).y - (*p1).y, (*p2).z - (*p1).z};
    r = norm_vec3d(p);
    F = (vec3d){p.x * c, p.y * c, p.z * c};

    (*v1).x += F.x * step / (2 * m1);
    (*v1).y += F.y * step / (2 * m1);
    (*v1).z += F.z * step / (2 * m1);

    (*v2).x -= F.x * step / (2 * m2);
    (*v2).y -= F.y * step / (2 * m2);
    (*v2).z -= F.z * step / (2 * m2);
}