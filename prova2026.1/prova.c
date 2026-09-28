#include <stdio.h>

#define QTD_COLUNAS 3


// letra a
int removerRepetidos(int v[], int tam) {
    int novoTam = 1;

    for (int i = 1; i < tam; i++) {
        if (v[i] != v[novoTam - 1]) {
            v[novoTam] = v[i];
            novoTam++;
        }
    }

    return novoTam;
}

// letra b
void ordenar(int v[], int tam) {
    int i, j, temp;

    for (i = 0; i < tam - 1; i++) {
        for (j = 0; j < tam - 1 - i; j++) {

            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}


// letra c
void preencherPrimos(int v[], int tam) {
    int qtd = 0;
    int numero = 2;
    int primo;
    int i;

    while (qtd < tam) {
        primo = 1;

        for (i = 0; i < qtd; i++) {
            if (numero % v[i] == 0) {
                primo = 0;
                break;
            }
        }

        if (primo == 1) {
            v[qtd] = numero;
            qtd++;
        }

        numero++;
    }
}


// letra d
void maiorPorLinha(int m[][QTD_COLUNAS], int lin, int col, int v[]) {
    int i, j;
    int maior;

    for (i = 0; i < lin; i++) {
        maior = m[i][0];

        for (j = 1; j < col; j++) {
            if (m[i][j] > maior) {
                maior = m[i][j];
            }
        }

        v[i] = maior;
    }
}


// letra e
void inverterPalavras(char str[]) {
    int inicio = 0;
    int fim;
    char temp;

    while (str[inicio] != '\0') {

        if (str[inicio] == ' ') {
            inicio++;
        } else {
            fim = inicio;

            while (str[fim] != ' ' && str[fim] != '\0') {
                fim++;
            }

            fim--;

            while (inicio < fim) {
                temp = str[inicio];
                str[inicio] = str[fim];
                str[fim] = temp;

                inicio++;
                fim--;
            }

            inicio = fim + 1;
        }
    }
}


int main() {

    //teste letra a

    int v1[] = {3, 3, 4, 5, 6, 6, 6, 7};
    int tam1 = 8;

    tam1 = removerRepetidos(v1, tam1);

    printf("Teste 1 - Remover repetidos:\n");

    for (int i = 0; i < tam1; i++) {
        printf("%d ", v1[i]);
    }

    printf("\nNovo tamanho: %d\n\n", tam1);


    //teste letra b

    int v2[] = {8, 3, 10, 1, 5};
    int tam2 = 5;

    ordenar(v2, tam2);

    printf("Teste 2 - Bubble Sort:\n");

    for (int i = 0; i < tam2; i++) {
        printf("%d ", v2[i]);
    }

    printf("\n\n");


    // teste letra c

    int v3[5];

    preencherPrimos(v3, 5);

    printf("Teste 3 - Números primos:\n");

    for (int i = 0; i < 5; i++) {
        printf("%d ", v3[i]);
    }

    printf("\n\n");


    // teste letra d

    int matriz[3][QTD_COLUNAS] = {
        {10, 5, 20},
        {8, 15, 3},
        {7, 2, 9}
    };

    int v4[3];

    maiorPorLinha(matriz, 3, QTD_COLUNAS, v4);

    printf("Teste 4 - Maior de cada linha:\n");

    for (int i = 0; i < 3; i++) {
        printf("%d ", v4[i]);
    }

    printf("\n\n");


    // teste letra e

    char str[] = "o rato roeu";

    inverterPalavras(str);

    printf("Teste 5 - Inverter palavras:\n");
    printf("%s\n", str);


    return 0;
}