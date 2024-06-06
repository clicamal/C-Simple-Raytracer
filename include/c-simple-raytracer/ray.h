#ifndef RAY_H
#define RAY_H

#include "c-simple-raytracer/vector3d.h"
#include <stdlib.h>
#include <math.h>

typedef struct ray_s {
    vector3d_s *origin;
    vector3d_s *destination;
    vector3d_s *direction;
} ray_s;

ray_s *trace_ray(vector3d_s *origin, vector3d_s *destination);

void destroy_ray(ray_s *ray);

#endif