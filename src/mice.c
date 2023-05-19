#include "vec2d.h"
#include "vec3d.h"
#include "simulate.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11
#define m_A 1.0e11
#define m_B 1.0e11
#define r_min 25
#define t_i -16.4
#define t_f 6.086
#define dt 0.01

float gravitational_force(float m1, float m2, float r); 
vec2d acceleration(float m1, float m2, float r, vec2d pos);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("No argument provided.\n");
        return 1;
    }

    int arg = atoi(argv[1]);

    int steps = (t_f - t_i)/dt + 1;

    switch (arg) {
        case 1: {
            FILE* file = fopen("1.dat", "w");
            if (file == NULL) {
                printf("Failed to open file.\n");
                return 1;
            }

            vec2d p_A = {0.7 * r_min, 0};
            vec2d v_A = {0, sqrt(1 + exp(1) * G * m_B / (0.7 * r_min))};
            vec2d p_B = {-0.7 * r_min, 0};
            vec2d v_B = {0, -sqrt(1 + exp(1) * G * m_A / (0.7 * r_min))};
            
            for(int i = 0; i <= steps; i++)
            {
                float r_A = norm_vec2d(p_A);
                float r_B = norm_vec2d(p_B);
                vec2d a_A = acceleration(m_A, m_B, r_A, p_A);
                vec2d a_B = acceleration(m_B, m_A, r_B, p_B);
                leapfrog1(&p_A, &v_A, &a_A, dt);
                leapfrog1(&p_B, &v_B, &a_B, dt);

                fprintf(file, "%f,%f,%f,%f\n", p_A.x, p_A.y, p_B.x, p_B.y);
            }
            fclose(file);
            break;
        }

        case 2: {
            FILE* file = fopen("2.dat", "w");
                if (file == NULL) {
                printf("Failed to open file.\n");
                return 1;
            }

            float m1 = 1.0;
            vec3d p1 = {-1.0, 0.0, 0.0};
            vec3d v1 = {0.0, -0.5, 0.0};

            float m2 = 1.0;
            vec3d p2 = {1.0, 0.0, 0.0};
            vec3d v2 = {0.0, 0.5, 0.0};

            for(int i = 0; i <= steps; i++)
            {
                leapfrog2(&p1, &v1, &p2, &v2, m1, m2, dt);
                fprintf(file, "%f,%f,%f,%f,%f,%f\n", p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
            }
            fclose(file);
            break;
        }

        case 3: {
            FILE* file = fopen("3.dat", "w");
                if (file == NULL) {
                printf("Failed to open file.\n");
                return 1;
            }

            float m1 = 1.0;
            float r1 = 1.0;
            vec3d p1 = {-1.0, 0.0, 0.0};
            vec3d v1 = {0.0, -0.5, 0.0};

            float m2 = 1.0;
            float r2 = 1.0;
            vec3d p2 = {1.0, 0.0, 0.0};
            vec3d v2 = {0.0, 0.5, 0.0};

            for(int i = 0; i <= steps; i++)
            {
                leapfrog3(&p1, &v1, &p2, &v2, m1, m2, r1, r2, dt);
                fprintf(file, "%f,%f,%f,%f,%f,%f\n", p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
            }
            fclose(file);
            break;
        }

        default: {
            printf("Invalid argument.\n");
            return 1;
        }
    }

    return 0;
}

float gravitational_force(float m1, float m2, float r)
{
    return G * m1 * m2 / (r * r);
}

vec2d acceleration(float m1, float m2, float r, struct vec2d pos)
{
    float c = gravitational_force(m1, m2, r) / (m1 * r);
    return (vec2d) {pos.x * c, pos.y * c};
}