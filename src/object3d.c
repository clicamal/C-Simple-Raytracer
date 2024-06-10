#include "c-simple-raytracer/object3d.h"

sphere_s *create_sphere(vector3d_s* center, float radius) {
    sphere_s *sphere = malloc(sizeof(sphere_s));

    if (sphere == NULL) return sphere;

    sphere->center = center;
    sphere->radius = radius;

    return sphere;
}

void destroy_sphere(sphere_s *sphere) {
    destroy_vector3d(sphere->center);

    free(sphere);
    sphere = NULL;
}

object3d_s *create_object3d(object3d_type_e type, color_s *color, ...) {
    object3d_s *object3d = malloc(sizeof(object3d_s));
    va_list args;

    if (object3d == NULL) exit(ALLOCATION_ERROR);

    va_start(args, color);

    if (type == SPHERE) {
        sphere_s *object3d_sphere_self = va_arg(args, sphere_s*);

        object3d->self.sphere = object3d_sphere_self;
    }

    else {
        free(object3d);
        exit(INVALID_OBJECT3D_TYPE_ERROR);
    }

    object3d->type = type;
    object3d->color = color;

    va_end(args);

    return object3d;
}

void destroy_object3d(object3d_s *object3d) {
    if (object3d->type == SPHERE) {
        destroy_sphere(object3d->self.sphere);
    }

    else {
        exit(INVALID_OBJECT3D_TYPE_ERROR);
    }

    destroy_color(object3d->color);

    free(object3d);
    object3d = NULL;
}