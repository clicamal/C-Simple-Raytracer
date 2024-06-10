#include "c-simple-raytracer/math.h"

float calculate_vector3ds_dot_product(vector3d_s *a, vector3d_s *b) {
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

int8_t compare_vector3ds(vector3d_s *a, vector3d_s *b) {
    if (a->x == b->x && a->y == b->y && a->z == b->z) {
        return 0;
    } else if (a->x < b->x || (a->x == b->x && a->y < b->y) || (a->x == b->x && a->y == b->y && a->z < b->z)) {
        return -1;
    } else {
        return 1;
    }
}

vector3d_s *subtract_vector3ds(vector3d_s *a, vector3d_s *b) {
    return create_vector3d(
        a->x - b->x,
        a->y - b->y,
        a->z - b->z
    );
}

vector3d_s *calculate_ray_intersection_with_object3d(ray_s *ray, object3d_s *object3d) {
    float a, b, c, discriminant;

    if (object3d->type == SPHERE) {
        vector3d_s *oc = subtract_vector3ds(ray->origin, object3d->self.sphere->center);

        a = calculate_vector3ds_dot_product(ray->direction, ray->direction);
        b = 2 * calculate_vector3ds_dot_product(oc, ray->direction);
        c = calculate_vector3ds_dot_product(oc, oc) - object3d->self.sphere->radius;

        destroy_vector3d(oc);

        discriminant = pow(b, 2) - 4 * a * c;

        if (discriminant < 0) {
            return NULL;
        } else {
            float solution = (-b - sqrt(discriminant)) / (2 * a);

            return create_vector3d(
                ray->origin->x + solution * ray->direction->x,
                ray->origin->y + solution * ray->direction->y,
                ray->origin->z + solution * ray->direction->z
            );
        }
    } else {
        exit(INVALID_OBJECT3D_TYPE_ERROR);
    }

    return NULL;
}