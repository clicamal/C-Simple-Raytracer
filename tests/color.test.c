#include "c-simple-raytracer/color.h"
#include <assert.h>

int main(void) {
    color_s *color = create_color(255, 255, 255);

    assert(color != NULL);
    assert(color->r == 255);
    assert(color->g == 255);
    assert(color->b == 255);

    destroy_color(color);

    assert(color == NULL);

    return 0;
}