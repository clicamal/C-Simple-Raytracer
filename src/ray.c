#include "c-simple-raytracer/ray.h"

ray_s *trace_ray(vector3d_s *origin, vector3d_s *destination) {
    ray_s *ray = malloc(sizeof(vector3d_s));

    if (ray == NULL) return ray;

    ray->origin = origin;
    ray->destination = destination;

    ray->direction = create_vector3d(
        destination->x - origin->x,
        destination->y - origin->y,
        destination->z - origin->z
    );
    
    float magnitude = sqrt(pow(ray->direction->x, 2) + pow(ray->direction->y, 2) + pow(ray->direction->z, 2));

    ray->direction->x /= magnitude;
    ray->direction->y /= magnitude;
    ray->direction->z /= magnitude;

    return ray;
}

void destroy_ray(ray_s *ray) {
    destroy_vector3d(ray->origin);
    destroy_vector3d(ray->destination);
    destroy_vector3d(ray->direction);

    free(ray);
    ray = NULL;
}