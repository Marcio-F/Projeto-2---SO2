#include "../include/screen.h"
#include "../include/kb.h"
#include "../include/string.h"
#include "../include/isr.h"
#include "../include/shell.h"

int kmain() {
    isr_install();
    clearScreen();

    print("\t\t\t\t    SimpleOS");
    print("\n\n");

    launch_shell(0);

    return 0;
}
