/**
 * \file fragment.h
 *
 * Declares a low-level text segment for output and rendering.
 *
 * \author H Paterson.
 * \copyright BSL-1.0.
 */

#ifndef FRAGMENT_H
#define FRAGMENT_H

#include "colour.h"
#include <stddef.h>

/** Offset, or position, of a renderable object. */
typedef struct PcOffset {
    const unsigned int x;
    const unsigned int y;
} pc_offset_t;

struct PcFragment {
    /**
     * Printable glyphs in the fragment.
     *
     * `body` should only glyphs representing a single space in the text,
     * and no newline symbols in particular.
     */
    const wchar_t* const body;

    /** Apparence of the glypths in the body. */
    const pc_colour_t style;

    /**
     * Position of the fragment.
     *
     * The position may be the location in terminal space, or a local position
     * relative to another object depending on the context.
     */
    pc_offset_t position;
};

#endif // FRAGMENT_H
