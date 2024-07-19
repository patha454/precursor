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


struct PcTerminal
{
    FILE* out;
};

void pcInitTerminalDefault(struct PcTerminal* terminal);


/**
 * Change the foreground colour.
 *
 * \param terminal Terminal insance to modify.
 * \param colour Forground colour to use for future printing.
 */
void pcSetForeground(struct PcTerminal* terminal, pc_colour_t colour);

/**
 * Change the background colour.
 *
 * \param terminal Terminal insance to modify.
 * \param colour Background colour to use for future printing.
 */
void pcSetBackground(struct PcTerminal* terminal, pc_colour_t colour);

/**
 * Controls the use of bold text.
 *
 *\param terminal Terminal instance to modify.
 *\param enable Indicates if future output should be em-boldend.
 */
void pcSetBold(struct PcTerminal* terminal, bool enable);

/**
 *
 * Controls the use of italics text.
 *
 * \param terminal Terminal instance to modify.
 * \param enable indicates if future output should be itatics'ed.
 */
void pcSetItalic(struct PcTerminal* terminal, bool enable);

void pcReset(struct PcTerminal* terminal);

#endif //PRECURSOR_TERMINAL_H
