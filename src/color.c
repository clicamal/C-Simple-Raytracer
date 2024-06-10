#include "c-simple-raytracer/color.h"
#include "c-simple-raytracer/error.h"

color_s *create_color(uint8_t r, uint8_t g, uint8_t b) {
    color_s *color = malloc(sizeof(color_s));

    if (color == NULL) exit(ALLOCATION_ERROR);

    color->r = r;
    color->g = g;
    color->b = b;

    return color;
}

void destroy_color(color_s *color) {
    free(color);
    color = NULL;
}