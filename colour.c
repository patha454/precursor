#include "colour.h"

pc_colour_t PcColour(const uint8_t red, const uint8_t green, const uint8_t blue)
{
    const pc_colour_t colour = {
    .red = red,
    .blue = blue,
    .green = green
    };
    return colour;
}
