#include "c-simple-raytracer/ray.h"
#include <assert.h>
#include <math.h>

int main(void) {
    ray_s *ray = trace_ray(
        create_vector3d(0, 0, 0),
        create_vector3d(1, 1, 1)
    );

    assert(ray != NULL);

    assert(ray->origin->x == 0);
    assert(ray->origin->y == 0);
    assert(ray->origin->z == 0);

    assert(ray->destination->x == 1);
    assert(ray->destination->y == 1);
    assert(ray->destination->z == 1);

    assert(isnormal(ray->direction->x));
    assert(isnormal(ray->direction->y));
    assert(isnormal(ray->direction->z));

    float magnitude = sqrt(pow(ray->direction->x, 2) + pow(ray->direction->y, 2) + pow(ray->direction->z, 2));

    assert(abs(ray->direction->x - (ray->destination->x - ray->origin->x) / magnitude) < __FLT_EPSILON__);
    assert(abs(ray->direction->y - (ray->destination->y - ray->origin->y) / magnitude) < __FLT_EPSILON__);
    assert(abs(ray->direction->z - (ray->destination->z - ray->origin->z) / magnitude) < __FLT_EPSILON__);

    destroy_ray(ray);

    assert(ray == NULL);

    return 0;
}