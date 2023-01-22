#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "system.h"
#include "string.h"

extern int32 cursorX, cursorY;
extern const uint8 sw, sh, sd;

extern void clearLine(uint8 from, uint8 to);

extern void updateCursor();

/*
    A função clearScreen() limpa a tela ao ir limpando linha por linha utilizando a 
    função clearLine(), e ao final retorna o cursor para a posição (0, 0) e então
    atualiza o cursor com a função clearScreen().
*/
extern void clearScreen();

/*
    A função scrollUp() recebe um número de linhas que serão deslocadas para cima
    e então copia o conteúdo da tela para cima e limpa a última linha da tela.
*/
extern void scrollUp(uint8 lineNumber);

/*
    A função newLineCheck() verifica se o cursor está na última linha da tela, se
    estiver, então a função scrollUp() é chamada para deslocar a tela para cima.
*/
extern void newLineCheck();

/*
    A função printch() recebe um caractere e então verifica se o caractere é um
    caractere especial, se for, então a função trata o caractere de acordo com
    o seu valor, se não for, então o caractere é impresso na tela e o cursor é
    atualizado.
*/
extern void printch(char c);

/*
    A função print() recebe uma string e então imprime cada caractere da string
    na tela utilizando a função printch().
*/
extern void print(string ch);

#endif
