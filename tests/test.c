#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
    
typedef struct color_s {
    uint8_t r, g, b;
} color_s;

color_s *create_color(uint8_t r, uint8_t g, uint8_t b) {
    color_s *color = malloc(sizeof(color_s));

    color->r = r;
    color->g = g;
    color->b = b;

    return color;
}

void destroy_color(color_s *color) { free(color); }

int main(void) {
    FILE *output_img = fopen("img.ppm", "w");

    int img_width = 512;
    int img_height = 512;

    color_s *background_color = create_color(255, 255, 255);

    fprintf(output_img, "P3 %d %d %d", img_width, img_height, 255);

    for (int y = img_height - 1; y >= 0; y--) {
        for (int x = img_width - 1; x >= 0; x--) {
            fprintf(output_img, " %d %d %d", background_color->r, background_color->g, background_color->b);
        }
    }

    destroy_color(background_color);
    fclose(output_img);

    return 0;
}