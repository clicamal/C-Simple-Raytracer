#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <stdlib.h>

typedef struct vector3d_s {
    float x, y, z;
} vector3d_s;

vector3d_s *create_vector3d(float x, float y, float z);

void destroy_vector3d(vector3d_s *vector3d);

#endif