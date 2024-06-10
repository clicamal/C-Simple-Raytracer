#include <stdio.h>
#include <math.h>
#include "c-simple-raytracer/c-simple-raytracer.h"

int main(void) {
    FILE *output_img = fopen("../img.ppm", "w");

    int
        img_width = 512,
        img_height = 512;

    float
        aspect_ratio = img_width / img_height,
        scale = 1,
        normal_cartesian_coord_x,
        normal_cartesian_coord_y;

    color_s *background_color = create_color(255, 255, 255);

    vector3d_s
        *camera_position = create_vector3d(0, 0, 0),
        *light_source = create_vector3d(5, 5, 5),
        *primary_intersection_point;

    ray_s *primary_ray;

    scene_object3d_s
        *scene = create_scene_object3d(NULL),
        *scene_current_object3d;

    add_object3d_to_scene(
        scene,
        create_object3d(
            SPHERE,
            create_color(255, 0, 0),
            create_sphere(
                create_vector3d(0, 0, 5),
                1
            )
        )
    );

    fprintf(output_img, "P3 %d %d %d", img_width, img_height, 255);

    for (int y = 0; y < img_height; y++) {
        for (int x = 0; x < img_width; x++) {
            normal_cartesian_coord_x = (-img_width / 2 + x) * scale / img_width * aspect_ratio;
            normal_cartesian_coord_y = (img_height / 2 - y) * scale / img_height;

            primary_ray = trace_ray(
                create_vector3d(camera_position->x, camera_position->y, camera_position->z),
                create_vector3d(normal_cartesian_coord_x, normal_cartesian_coord_y, 1)
            );

            scene_current_object3d = scene;

            while (scene_current_object3d != NULL) {
                primary_intersection_point = calculate_ray_intersection_with_object3d(primary_ray, scene_current_object3d->current);

                if (primary_intersection_point != NULL) break;

                scene_current_object3d = scene_current_object3d->next;
            }
            
            destroy_ray(primary_ray);

            if (scene_current_object3d == NULL) {
                fprintf(output_img, " %d %d %d", background_color->r, background_color->g, background_color->b);
            } else {
                ray_s *shadow_ray = trace_ray(
                    create_vector3d(
                        primary_intersection_point->x,
                        primary_intersection_point->y,
                        primary_intersection_point->z
                    ),
                    subtract_vector3ds(
                        light_source,
                        primary_intersection_point
                    )
                );

                scene_object3d_s *scene_current_shadow_object3d = scene;

                vector3d_s *shadow_intersection_point;

                while (scene_current_shadow_object3d != NULL) {
                    shadow_intersection_point = calculate_ray_intersection_with_object3d(shadow_ray, scene_current_shadow_object3d->current);

                    if (shadow_intersection_point != NULL) break;

                    scene_current_shadow_object3d = scene_current_shadow_object3d->next;
                }

                destroy_ray(shadow_ray);

                vector3d_s *primary_intersection_point_and_light_source_distance = subtract_vector3ds(light_source, primary_intersection_point);
                vector3d_s *shadow_intersection_point_and_light_source_distance = NULL;

                if (shadow_intersection_point != NULL) shadow_intersection_point_and_light_source_distance = subtract_vector3ds(light_source, shadow_intersection_point);

                if (scene_current_shadow_object3d != NULL && compare_vector3ds(primary_intersection_point_and_light_source_distance, shadow_intersection_point_and_light_source_distance) > 0) {
                    fprintf(output_img, " 0 0 0");
                }

                else {
                    fprintf(output_img, " %d %d %d", scene_current_object3d->current->color->r, scene_current_object3d->current->color->g, scene_current_object3d->current->color->b);
                }

                if (shadow_intersection_point_and_light_source_distance != NULL) destroy_vector3d(shadow_intersection_point_and_light_source_distance);
                destroy_vector3d(primary_intersection_point_and_light_source_distance);
                destroy_vector3d(primary_intersection_point);
                destroy_vector3d(shadow_intersection_point);
            }
        }
    }

    destroy_scene(scene);
    destroy_vector3d(camera_position);
    destroy_color(background_color);
    fclose(output_img);

    return 0;
}