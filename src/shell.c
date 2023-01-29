#include "../include/shell.h"

void gcd();

void launch_shell(int n) {
    string ch = (string) malloc(200); //definido em util.h

    do {
        print("SimpleOS (");
        print(int_to_string(n));
        print(")>");
        
        ch = readStr(); // memory_copy(readStr(), ch, 100);

        if(strEql(ch, "cmd")) {
            print("\nVoce ja esta no cmd. Novo shell recursivo aberto...\n\n");
            launch_shell(n+1);
        }
        else if (strEql(ch, '\0'));
        else if (strEql(ch, "clear"))
            clearScreen();
        else if (strEql(ch, "soma"))
            sum();
        else if (strEql(ch, "exit")) {
            print("\nSaindo do SimpleOS...\n");
            asm("hlt");
        }
        else if (strEql(ch, "echo"))
            echo();
        else if (strEql(ch, "sort"))
            sort();
        else if (strEql(ch, "fibo"))
            fibonacci();
        else if (strEql(ch, "mmc"))
            gcd();
        else if (strEql(ch, "help"))
            help();
        else if (strEql(ch, "cor"))
            set_bg_color();
        else if (strEql(ch, "quit")) {
            if (n > 0) {
                print("\nSaindo do shell atual...\n\n");
                launch_shell(n-1);
            }
            else {
                print("\nVoce ja esta no shell primario...\n");
            }
        }
        else {
            print("\n");
            print(ch);
            print(": command not found\n");
        }

        print("\n");
    } while(!strEql(ch,"exit"));
}

void sum() {
    int n, i, s;

    print("\nQuantos numeros: ");

    n = str_to_int(readStr());
    i = 0;

    print("\n");

    int arr[n];

    fill_array(arr, n);

    s = sum_array(arr, n);

    print("\nResultado: ");
    print(int_to_string(s));
    print("\n");
}

void fill_array(int arr[], int n) {
    int i;

    print("\n");

    for (i = 0; i < n; i++) {
        print("ARR[");
        print(int_to_string(i));
        print("]:");

        arr[i] = str_to_int(readStr());

        print("\n");
    }
}

void print_array(int arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        print(int_to_string(arr[i]));
        print(" ");
    }

    print("\n");
}

int sum_array(int arr[], int n) {
    int i;
    int s = 0;

    for (i = 0; i < n; i++) {
        s += arr[i];
    }

    return s;
}

void echo() {
    print("\n");

    string str = readStr();

    print("\n\n");
    print(str);
    print("\n");
}

void sort() {
    int arr[100];

    print("\nTamanho do vetor: ");

    int n = str_to_int(readStr());

    fill_array(arr, n);

    print("\n\nAntes da ordenacao:\n");
    print_array(arr,n);
    print("\nOrdem: (1 - crescente/ 0 - decrescente): ");

    int order = str_to_int(readStr());

    insertion_sort(arr, n, order);

    print("\n\nApos ordenacao:\n");
    print_array(arr, n);
}

void insertion_sort(int arr[], int n, int order) {
    // 1 - crescente e 0 - decrescente
    int i;

    for (i = 0; i < n; i++) {
        int aux = arr[i];
        int j = i;

        while((j > 0) && ((aux < arr[j-1]) && order)) {
            arr[j] = arr[j-1];
            j = j-1;
        }

        arr[j] = aux;
    }
}

void fibonacci() {
    int i, n;

    print("\nQuantos elementos: ");

    n = str_to_int(readStr());

    print("\n");

    for (i = 0; i < n; i++) {
        print("\nFibo ");
        print(int_to_string(i));
        print(" : ");
        print(int_to_string(fibo(i)));
    }

    print("\n");

}

int fibo(int n) {
    if (n < 2)
        return 1;
    else
        return fibo(n-1) + fibo (n-2);
}

int gcd_array(int arr[], int n) {
    int i, j, k, gcd, mmc;

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            gcd = 1;
            for (k = 2; k <= arr[i] && k <= arr[j]; k++) {
                if (arr[i] % k == 0 && arr[j] % k == 0) {
                    gcd = k;
                }
            }

            mmc = (arr[i] * arr[j]) / gcd;

            arr[j] = mmc;
        }
    }

    return arr[n-1];
}

void gcd() {
    print("\nDigite quantos numeros: ");
    int n = str_to_int(readStr());

    print("\n");

    int arr[n];

    fill_array(arr, n);

    print("\nMMC: ");
    print(int_to_string(gcd_array(arr, n)));
    print("\n");
}

void set_bg_color() {
    print("\nCodigos de cores: ");
    print("\n0 : preto");
    print_colored("\n1 : azul", 1,0);
    print_colored("\n2 : verde", 2,0);
    print_colored("\n3 : ciano", 3,0);
    print_colored("\n4 : vermelho", 4,0);
    print_colored("\n5 : purpura", 5,0);
    print_colored("\n6 : laranja", 6,0);
    print_colored("\n7 : cinza", 7,0);
    print_colored("\n8 : cinza escuro", 8,0);
    print_colored("\n9 : azul claro", 9,0);
    print_colored("\n10 : verde claro", 10,0);
    print_colored("\n11 : azul mais claro", 11,0);
    print_colored("\n12 : vermelho claro", 12,0);
    print_colored("\n13 : rosa", 13,0);
    print_colored("\n14 : amarelo", 14,0);
    print_colored("\n15 : branco", 15,0);

    print("\n\nCor do texto: ");
    int text_color = str_to_int(readStr());

    print ("\n\nCor do fundo: ");
    int bg_color = str_to_int(readStr());

    set_screen_color(text_color, bg_color);
    clearScreen();
}

void help() {
    print("\ncmd\t: executa um novo shell recursivo");
    print("\nclear\t: limpa a tela");
    print("\nsoma\t: computa a soma de n numeros");
    print("\necho\t: imprime um dado texto");
    print("\nsort\t: ordena n numeros");
    print("\nfibo\t: imprime os n primeiros numeros da serie de Fibonacci");
    print("\nmmc\t: computa o MMC de n numeros");
    print("\ncor\t: muda a cor do terminal");
    print("\nquit\t: sai do shell corrente");
    print("\nexit\t: termina o sistema");
    print("\nhelp\t: imprime esta mensagem");
    print("\n");
}
