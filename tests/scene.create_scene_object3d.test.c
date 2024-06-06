#include "c-simple-raytracer/scene.h"
#include <assert.h>

int main(void) {
    scene_object3d_s *scene = create_scene_object3d(NULL);

    assert(scene != NULL);

    assert(scene->current == NULL);
    assert(scene->next == NULL);

    add_object3d_to_scene(
        scene,
        create_object3d(
            SPHERE,
            create_color(255, 0, 0),
            create_sphere(
                create_vector3d(0, 0, 0),
                1
            )
        )
    );

    assert(scene->current != NULL);

    assert(scene->current->type == SPHERE);

    assert(scene->current->color->r == 255);
    assert(scene->current->color->g == 0);
    assert(scene->current->color->b == 0);

    assert(scene->current->self.sphere->center->x == 0);
    assert(scene->current->self.sphere->center->y == 0);
    assert(scene->current->self.sphere->center->z == 0);

    assert(scene->current->self.sphere->radius == 1);

    assert(scene->next == NULL);

    add_object3d_to_scene(
        scene,
        create_object3d(
            SPHERE,
            create_color(0, 255, 0),
            create_sphere(
                create_vector3d(1, 2, 3),
                1
            )
        )
    );

    assert(scene->next->current != NULL);

    assert(scene->next->current->type == SPHERE);

    assert(scene->next->current->color->r == 0);
    assert(scene->next->current->color->g == 255);
    assert(scene->next->current->color->b == 0);

    assert(scene->next->current->self.sphere->center->x == 1);
    assert(scene->next->current->self.sphere->center->y == 2);
    assert(scene->next->current->self.sphere->center->z == 3);

    assert(scene->next->current->self.sphere->radius == 1);

    assert(scene->next->next == NULL);

    destroy_scene(scene);

    assert(scene == NULL);

    return 0;
}