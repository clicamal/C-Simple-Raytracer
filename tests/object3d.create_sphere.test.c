#include "c-simple-raytracer/object3d.h"
#include <assert.h>

int main(void) {
    sphere_s *sphere = create_sphere(
        create_vector3d(0, 0, 0),
        1
    );

    assert(sphere != NULL);

    assert(sphere->center->x == 0);
    assert(sphere->center->y == 0);
    assert(sphere->center->z == 0);

    assert(sphere->radius == 1);

    destroy_sphere(sphere);

    assert(sphere == NULL);

    return 0;
}