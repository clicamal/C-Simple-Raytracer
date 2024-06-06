#include "c-simple-raytracer/vector3d.h"
#include <assert.h>

int main(void) {
    vector3d_s *vector3d = create_vector3d(0, 1, 2);

    assert(vector3d != NULL);
    assert(vector3d->x == 0);
    assert(vector3d->y == 1);
    assert(vector3d->z == 2);

    destroy_vector3d(vector3d);

    assert(vector3d == NULL);

    return 0;
}