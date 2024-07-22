#include "ansi_terminal.h"
#include "colour.h"
#include "terminal.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const struct PcTerminal terminal = ansiTerminal;
    for (unsigned int i = 0; i < 256; i += 32) {
        for (unsigned int j = 0; j < 256; j += 32) {
            const pc_colour_t fg = PcColour(i, j, 128);
            const pc_colour_t bg = PcColour(128, i, j);
            terminal.setForeground(stdout, fg);
            terminal.setBackground(stdout, bg);
            terminal.enableBold(stdout, true);
            printf("%03d", i);
            terminal.enableBold(stdout, false);
            terminal.enableItalic(stdout, true);
            printf("%03d|", j);
        }
        terminal.reset(stdout);
        printf("\n");
    }
    return EXIT_SUCCESS;
}
