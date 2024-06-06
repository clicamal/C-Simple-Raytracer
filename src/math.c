#include "c-simple-raytracer/math.h"

float normalize(float val, float max) {
    return val / max * 2 - 1;
}

float calculate_vector3ds_dot_product(vector3d_s *a, vector3d_s *b) {
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

bool ray_intersects_with_object3d(ray_s *ray, object3d_s *object3d) {
    float a, b, c, discriminant;

    if (object3d->type == SPHERE) {
        vector3d_s *oc = create_vector3d(
            ray->origin->x - object3d->self.sphere->center->x,
            ray->origin->y - object3d->self.sphere->center->y,
            ray->origin->z - object3d->self.sphere->center->z
        );

        a = calculate_vector3ds_dot_product(ray->direction, ray->direction);
        b = 2 * calculate_vector3ds_dot_product(oc, ray->direction);
        c = calculate_vector3ds_dot_product(oc, oc) - object3d->self.sphere->radius;

        destroy_vector3d(oc);

        discriminant = pow(b, 2) - 4 * a * c;

        if (discriminant < 0) return false;
    } else {
        exit(INVALID_OBJECT3D_TYPE_ERROR);
    }

    return true;
}