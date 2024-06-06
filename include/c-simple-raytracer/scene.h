#ifndef SCENE_H
#define SCENE_H

#include "c-simple-raytracer/object3d.h"
#include <stdlib.h>

typedef struct scene_object3d_s {
    object3d_s *current;
    struct scene_object3d_s *next;
} scene_object3d_s;

scene_object3d_s *create_scene_object3d(object3d_s *current);

void destroy_scene_object3d(scene_object3d_s *scene_object3d);

void add_object3d_to_scene(scene_object3d_s *scene_first_object3d, object3d_s *new_object3d);

void destroy_scene(scene_object3d_s *scene_first_object3d);

#endif