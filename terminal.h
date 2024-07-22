/**
 * \file terminal.h
 *
 * Platform agnostic interface to a terminal's rich I/O capabilites.
 *
 * Terminal is a top level wrapper containing implementaitons for a
 * particular terminal and settings.
 *
 * \author H Paterson.
 * \copyright BSL-1.0.
 */

#ifndef PRECURSOR_TERMINAL_H
#define PRECURSOR_TERMINAL_H

#include <stdio.h>
#include "colour.h"


/**
 * Select a colour to be used in future writes to the terminal.
 */
typedef void (*set_colour_t)(FILE *terminal, pc_colour_t colour);

/**
 * Enable or disable an an output mode for future writes to the terminal.
 *
 * An output mode may be a text style - such as bold or italics - or an output
 * mode - such as the alternative screen.
 */
typedef void (*enable_mode_t)(FILE *terminal, bool enable);

/**
 * Toggle a single-shot control for a terminal.
 *
 * The classic single-shot control is resetting the terminal to its original
 * styling.
 */
typedef void (*toggle_mode_t)(FILE *terminal);


/**
 * A device with rich I/O capabilities.
 *
 * `PcTerminals` is an interface for logical devices capible of
 * formatted output or interactive input. Terminals emulators are typical
 * terminal implementations, but could anything that interacts with a user
 * via test.
 *
 * A null method in a `PcTerminal` indicates a devices does not support the
 * relevent capability.
 *
 * `PcTerminal` implementations control the devices by writing escape sequences
 * , control codes, or markup to a file, as fits their underlying device.
 *
 * `PcTerminal` abstracts
 */
struct PcTerminal
{

    /** Change the foreground colour for future writes. */
    set_colour_t setForeground;

    /** Change the background colour for future writes. */
    set_colour_t setBackground;

    /** Enable or disable bold text for future writes. */
    enable_mode_t enableBold;

    /** Enable or disable italic text for future writes. */
    enable_mode_t enableItalic;

    /** Reset the terminal configuration. */
    toggle_mode_t reset;
};


#endif //PRECURSOR_TERMINAL_H
