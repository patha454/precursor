/**
 * \file colour.h
 *
 * Platform-agnostic interface to terminal's colouring
 * capabilities.
 *
 * Implementations of colouring should always prodouce output as requested.
 * Colour implementations are not responsible for determining a terminal's
 * capabilities, which implementation to use, or if the user prefers colouring.
 *
 * \author H Paterson.
 * \copyright BSL-1.0.
 */

#ifndef PRECURSOR_COLOUR_H
#define PRECURSOR_COLOUR_H

#include <stdint.h>

/**
 * Precursor's representation of a colour.
 *
 * Precursor always uses true-colour internally; some functions may
 * input or output in other colour depths, converting as required.
 */
typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pc_colour_t;

/**
 * Represent a colour using RGB values.
 *
 * @param red Red colour intensity.
 * @param green  Green colour intensity.
 * @param blue Blue colour intensity.
 * @return
 */
extern pc_colour_t PcColour(uint8_t red, uint8_t green, uint8_t blue);

#endif // PRECURSOR_COLOUR_H
