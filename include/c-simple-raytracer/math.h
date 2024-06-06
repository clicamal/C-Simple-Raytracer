#ifndef MATH_H
#define MATH_H

#include "c-simple-raytracer/error.h"
#include "c-simple-raytracer/ray.h"
#include "c-simple-raytracer/object3d.h"
#include <stdbool.h>
#include <math.h>

float normalize(float val, float max);

float calculate_vector3ds_dot_product(vector3d_s *a, vector3d_s *b);

bool ray_intersects_with_object3d(ray_s *ray, object3d_s *object3d);

#endif