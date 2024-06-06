#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "c-simple-raytracer/vector3d.h"
#include "c-simple-raytracer/color.h"
#include "c-simple-raytracer/error.h"
#include <stdarg.h>

typedef enum object3d_type_e {
    SPHERE
} object3d_type_e;

typedef struct sphere_s {
    vector3d_s *center;
    float radius;
} sphere_s;

typedef union object3d_self_u {
    sphere_s *sphere;
} object3d_self_u;

typedef struct object3d_s {
    object3d_type_e type;
    object3d_self_u self;
    color_s *color;
} object3d_s;

sphere_s *create_sphere(vector3d_s* center, float radius);

void destroy_sphere(sphere_s *sphere);

object3d_s *create_object3d(object3d_type_e type, color_s *color, ...);

void destroy_object3d(object3d_s *object3d);

#endif