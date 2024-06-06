#ifndef COLOR_H
#define COLOR_H

#include <stdlib.h>
#include <stdint.h>

typedef struct color_s {
    uint8_t r, g, b;
} color_s;

color_s *create_color(uint8_t r, uint8_t g, uint8_t b);

void destroy_color(color_s *color);

#endif