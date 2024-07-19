#include "terminal.h"
#include "colour.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    struct PcTerminal terminal;
    pcInitTerminalDefault(&terminal);
    pc_colour_t c = PcColour(198, 55, 137);
    pcSetForeground(&terminal, c);
    printf("struct PcColour size:\n");
    pcSetBold(&terminal, true);
    printf("Big bold ");
    pcSetBold(&terminal, false);
    printf("letters"),
    pcReset(&terminal);
    pcSetBackground(&terminal, c);
    printf("struct PcColour size:\n");
    return  EXIT_SUCCESS;
}