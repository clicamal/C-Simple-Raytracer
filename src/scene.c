#include "c-simple-raytracer/scene.h"

scene_object3d_s *create_scene_object3d(object3d_s *current) {
    scene_object3d_s *scene_object3d = malloc(sizeof(scene_object3d_s));

    if (scene_object3d == NULL) return scene_object3d;

    scene_object3d->current = current;
    scene_object3d->next = NULL;

    return scene_object3d;
}

void destroy_scene_object3d(scene_object3d_s *scene_object3d) {
    destroy_object3d(scene_object3d->current);
    free(scene_object3d);
    scene_object3d = NULL;
}

void add_object3d_to_scene(scene_object3d_s *scene_first_object3d, object3d_s *new_object3d) {
    if (scene_first_object3d->current == NULL) {
        scene_first_object3d->current = new_object3d;
    } else {
        scene_object3d_s *current_scene_object3d = scene_first_object3d;

        while (current_scene_object3d->next != NULL) current_scene_object3d = current_scene_object3d->next;
        
        current_scene_object3d->next = create_scene_object3d(new_object3d);
    }
}

void destroy_scene(scene_object3d_s *scene_first_object3d) {
    scene_object3d_s
        *current_scene_object3d = scene_first_object3d,
        *next_scene_object3d = NULL;

    while (current_scene_object3d != NULL) {
        scene_object3d_s *trash = current_scene_object3d;
        
        next_scene_object3d = current_scene_object3d->next;

        destroy_scene_object3d(trash);

        current_scene_object3d = next_scene_object3d;
    }

    free(scene_first_object3d);
    scene_first_object3d = NULL;
};