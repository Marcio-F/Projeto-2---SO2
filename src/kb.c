#include "../include/kb.h"

string readStr()
{
    char buff[256];
    string buffstr = buff;
    uint8 i = 0;
    uint8 reading = 1;

    while(reading) {
        if(inportb(0x64) & 0x1) {
            switch(inportb(0x60)) {
                case 0x01:
                    reading = 0;
                    break;
                case 0x02:
                    printch('1');
                    buffstr[i] = '1';
                    i++;
                    break;
                case 0x03:
                    printch('2');
                    buffstr[i] = '2';
                    i++;
                    break;
                case 0x04:
                    printch('3');
                    buffstr[i] = '3';
                    i++;
                    break;
                case 0x05:
                    printch('4');
                    buffstr[i] = '4';
                    i++;
                    break;
                case 0x06:
                    printch('5');
                    buffstr[i] = '5';
                    i++;
                    break;
                case 0x07:
                    printch('6');
                    buffstr[i] = '6';
                    i++;
                    break;
                case 0x08:
                    printch('7');
                    buffstr[i] = '7';
                    i++;
                    break;
                case 0x09:
                    printch('8');
                    buffstr[i] = '8';
                    i++;
                    break;
                case 0x0A:
                    printch('9');
                    buffstr[i] = '9';
                    i++;
                    break;
                case 0x0B:
                    printch('0');
                    buffstr[i] = '0';
                    i++;
                    break;
                case 0x0C:
                    printch('-');
                    buffstr[i] = '-';
                    i++;
                    break;
                case 0x0D:
                    printch('=');
                    buffstr[i] = '=';
                    i++;
                    break;
                case 0x0E:
                    if (i > 0) {
                        printch('\b');
                        i--;
                    }
                    break;
                case 0x0F:
                    printch('\t');
                    buffstr[i] = '\t';
                    i++;
                    break;
                case 0x10:
                    printch('q');
                    buffstr[i] = 'q';
                    i++;
                    break;
                case 0x11:
                    printch('w');
                    buffstr[i] = 'w';
                    i++;
                    break;
                case 0x12:
                    printch('e');
                    buffstr[i] = 'e';
                    i++;
                    break;
                case 0x13:
                    printch('r');
                    buffstr[i] = 'r';
                    i++;
                    break;
                case 0x14:
                    printch('t');
                    buffstr[i] = 't';
                    i++;
                    break;
                case 0x15:
                    printch('y');
                    buffstr[i] = 'y';
                    i++;
                    break;
                case 0x16:  
                    printch('u');
                    buffstr[i] = 'u';
                    i++;
                    break;
                case 0x17:
                    printch('i');
                    buffstr[i] = 'i';
                    i++;
                    break;
                case 0x18:
                    printch('o');
                    buffstr[i] = 'o';
                    i++;
                    break;
                case 0x19:
                    printch('p');
                    buffstr[i] = 'p';
                    i++;
                    break;
                case 0x1A:
                    printch((char) 49844);
                    buffstr[i] = (char) 49844;
                    i++;
                    break;
                case 0x1B:
                    printch('[');
                    buffstr[i] = '[';
                    i++;
                    break;
                case 0x1C:
                    if (i == 0) buffstr = '\0';
                    reading = 0;
                    break;
                /*
                case 0x1D: // Left ctrl
                    printch('l');
                    buffstr[i] = 'l';
                    i++;
                    break;
                */
                case 0x1E:
                    printch('a');
                    buffstr[i] = 'a';
                    i++;
                    break;
                case 0x1F:
                    printch('s');
                    buffstr[i] = 's';
                    i++;
                    break;
                case 0x20:
                    printch('d');
                    buffstr[i] = 'd';
                    i++;
                    break;
                case 0x21:
                    printch('f');
                    buffstr[i] = 'f';
                    i++;
                    break;
                case 0x22:
                    printch('g');
                    buffstr[i] = 'g';
                    i++;
                    break;
                case 0x23:
                    printch('h');
                    buffstr[i] = 'h';
                    i++;
                    break;
                case 0x24:
                    printch('j');
                    buffstr[i] = 'j';
                    i++;
                    break;
                case 0x25:
                    printch('k');
                    buffstr[i] = 'k';
                    i++;
                    break;
                case 0x26:
                    printch('l');
                    buffstr[i] = 'l';
                    i++;
                    break;
                case 0x27:
                    printch((char) 50087);
                    buffstr[i] = (char) 50087;
                    i++;
                    break;
                case 0x28:  
                    printch('~');
                    buffstr[i] = '~';
                    i++;
                    break;
                case 0x29:  
                    printch('`');
                    buffstr[i] = '`';
                    i++;
                    break;
                /*
                case 0x2A: // Left shift
                    printch('l');
                    buffstr[i] = 'l';
                    i++;
                    break;
                */
                case 0x2B:
                    printch(']');
                    buffstr[i] = ']';
                    i++;
                    break;
                case 0x2C:
                    printch('z');
                    buffstr[i] = 'z';
                    i++;
                    break;
                case 0x2D:
                    printch('x');
                    buffstr[i] = 'x';
                    i++;
                    break;
                case 0x2E:
                    printch('c');
                    buffstr[i] = 'c';
                    i++;
                    break;
                case 0x2F:
                    printch('v');
                    buffstr[i] = 'v';
                    i++;
                    break;
                case 0x30:
                    printch('b');
                    buffstr[i] = 'b';
                    i++;
                    break;
                case 0x31:
                    printch('n');
                    buffstr[i] = 'n';
                    i++;
                    break;
                case 0x32:
                    printch('m');
                    buffstr[i] = 'm';
                    i++;
                    break;
                case 0x33:
                    printch(',');
                    buffstr[i] = ',';
                    i++;
                    break;
                case 0x34:
                    printch('.');
                    buffstr[i] = '.';
                    i++;
                    break;
                case 0x35:
                    printch(';');
                    buffstr[i] = ';';
                    i++;
                    break;
                /*
                case 0x36: Right shift
                    printch('l');
                    buffstr[i] = 'l';
                    i++;
                    break;
                */
                case 0x37:
                    printch('*');
                    buffstr[i] = '*';
                    i++;
                    break;
                /*
                case 0x38: Left alt
                    printch('l');
                    buffstr[i] = 'l';
                    i++;
                    break;
                */
                case 0x39:
                    printch(' ');
                    buffstr[i] = ' ';
                    i++;
                    break;
            }
        }
    }
    buffstr[i] = 0;
    
    return buffstr;
}
