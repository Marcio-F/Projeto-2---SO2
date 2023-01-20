#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"

kmain() {
    clearScreen();

    print("\t\t\t\t    SimpleOS");
    print("\n\n");

    while (1) {
        print("SimpleOS> ");

        string input = readStr();

        if (strEql(input, "clear\r") || strEql(input, "cls\r")) {
            clearScreen();
        } else if (strEql(input, "exit\r")) {
            print("\n\nExiting...\n");
            break;
        } else if (strEql(input, "\r")) {
            print(input);
        } else {
            print("\nUnknown command: ");
            print(input);
            print("\n");
        }

        print("\n");
    }
}
