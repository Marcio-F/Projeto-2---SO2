#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/isr.h"

kmain() {
    isr_install();
    clearScreen();

    print("\t\t\t\t    SimpleOS");
    print("\n\n");

    // Testando uma ISR
    int n = 2 / 0; // Irá imprimir a mensagem de exceção "Division by Zero"

    // while (1) {
    //     print("SimpleOS> ");

    //     string input = readStr();

    //     if (strEql(input, "clear\r") || strEql(input, "cls\r")) {
    //         clearScreen();
    //     } else if (strEql(input, "exit\r")) {
    //         print("\n\nExiting...\n");
    //         break;
    //     } else if (strEql(input, "\r")) {
    //         print(input);
    //     } else {
    //         print("\nUnknown command: ");
    //         print(input);
    //         print("\n");
    //     }

    //     print("\n");
    // }
}
