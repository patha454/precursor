/**
 * \file ansi_terminal.c
 *
 * Implementation of ANSI terminal control codes.
 *
 * \author H Paterson.
 * \copyright BSL-1.0.
 */

#include "terminal.h"
#include <stdbool.h>

static void ansiSetForeground(FILE* terminal, const pc_colour_t colour)
{
    fprintf(
        terminal, "\x1b[38;2;%d;%d;%dm", colour.red, colour.green, colour.blue);
}

static void ansiSetBackground(FILE* terminal, const pc_colour_t colour)
{
    fprintf(
        terminal, "\x1b[48;2;%d;%d;%dm", colour.red, colour.green, colour.blue);
}

static void ansiSetBold(FILE* terminal, const bool bold)
{
    if (bold) {
        fputs("\x1b[1m", terminal);
    } else {
        fputs("\x1b[22m", terminal);
    }
}

static void ansiSetItalic(FILE* terminal, const bool enable)
{
    if (enable) {
        fputs("\x1b[3m", terminal);
    } else {
        fputs("\x1b[23m", terminal);
    }
}

static void ansiReset(FILE* terminal)
{
    const char* code = "\x1b[0m";
    fputs(code, terminal);
}

const struct PcTerminal ansiTerminal = {
    .setForeground = ansiSetForeground,
    .setBackground = ansiSetBackground,
    .enableBold = ansiSetBold,
    .enableItalic = ansiSetItalic,
    .reset = ansiReset,
};
