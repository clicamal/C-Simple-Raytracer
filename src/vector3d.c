#include "c-simple-raytracer/vector3d.h"

vector3d_s *create_vector3d(float x, float y, float z) {
    vector3d_s *vector3d = malloc(sizeof(vector3d_s));

    if (vector3d == NULL) return vector3d;

    vector3d->x = x;
    vector3d->y = y;
    vector3d->z = z;

    return vector3d;
}

void destroy_vector3d(vector3d_s *vector3d) {
    free(vector3d);
    vector3d = NULL;
}