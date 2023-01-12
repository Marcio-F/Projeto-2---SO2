#include "include/screen.h"

kmain() {
    char *vidmem = (char*) 0xb8000;
    // vidmem[0] = 'M';
    // vidmem[1] = 0x02; /* cor do caracter: verde */

    clearScreen();
    updateCursor();
    print("\t\t\t\t    SimpleSO");
    print("\n\n");
    print("\rHello World!");
}
