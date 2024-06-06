#include "c-simple-raytracer/object3d.h"
#include <assert.h>

int main(void) {
    object3d_s *object3d = create_object3d(
        SPHERE,
        create_color(255, 255, 255),
        create_sphere(
            create_vector3d(0, 0, 0),
            1
        )
    );

    assert(object3d != NULL);

    assert(object3d->type == SPHERE);

    assert(object3d->color->r == 255);
    assert(object3d->color->g == 255);
    assert(object3d->color->b == 255);

    assert(object3d->self.sphere->center->x == 0);
    assert(object3d->self.sphere->center->y == 0);
    assert(object3d->self.sphere->center->z == 0);

    assert(object3d->self.sphere->radius == 1);

    destroy_object3d(object3d);

    assert(object3d == NULL);

    return 0;
}