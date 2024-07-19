/**
* \file terminal.c
 *
 * Implimentations of terminal control codes.
 *
 * `terminal.c` is a bulk dump of capabilites during early development,
 * mostly consisting of what works in my development environment. Expect it to
 * be refactored and split up as more terminals and capabilties are added.
 *
 * \author H Paterson.
 * \copyright BSL-1.0.
 */


#include <assert.h>
#include "terminal.h"

void pcSetForeground(struct PcTerminal* terminal, pc_colour_t colour)
{
    fprintf(
        terminal->out,
        "\x1b[38;2;%d;%d;%dm",
        colour.red,
        colour.green,
        colour.blue
    );
}

void useBgAnsiTruecolour(struct PcTerminal* terminal, pc_colour_t colour)
{
    fprintf(
        terminal->out,
        "\x1b[48;2;%d;%d;%dm",
        colour.red,
        colour.green,
        colour.blue
    );
}

void pcReset(struct PcTerminal* terminal)
{
    char* code = "\x1b[0m";
    fputs(code, terminal->out);
}

void pcInitTerminalDefault(struct PcTerminal* terminal)
{
    assert(terminal != NULL);
    terminal->out = stdout;
}
