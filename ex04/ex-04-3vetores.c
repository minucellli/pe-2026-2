/*
Atividade feita em sala para criar 3 vetores, tamanho 15.
o primeiro vetor: é preenchido com números pares em sequência maiores que 100
o segundo é preenchido com números primos
o terceiro é um vetor somatório, onde o primeiro elemento é igual a soma do primeiro elemento do vetor 1 e o último elemento do vetor 2, o segundo elemento é igual a soma do segundo elemento do vetor 1 e o penúltimo elemento do vetor 2, e assim vai seguindo
*/

#include <stdio.h>

#define TAM 15

void imprimirVetor(int v[], int n);
void preencherPares(int v[], int n);
void preencherPrimos(int v[], int n);
void somatorio(int s[], int a[], int b[], int n);

int main() {
    int pares[TAM], primos[TAM], soma[TAM];
    preencherPares(pares, TAM);
    imprimirVetor(pares, TAM);
    preencherPrimos(primos, TAM);
    imprimirVetor(primos, TAM);
    somatorio(soma, pares, primos, TAM);
    imprimirVetor(soma, TAM);
    return 0;
}

void imprimirVetor(int v[], int n) {
    printf("{");
    if (n > 0) {
        printf(" %3d", v[0]);
        for (int i = 1; i < n; i += 1) {
            printf(", %3d", v[i]);
        }
    }
    printf(" }\n");
}

void preencherPares(int v[], int n) {
    for (int i = 0; i < n; i += 1) {
        v[i] = 102 + 2 * i;
    }
}

int ePrimo(int v[], int n, int x) {
    for (int i = 0; i < n; i += 1) {
        if (x % v[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void preencherPrimos(int v[], int n) {
    int i = 0, num = 2;
    while (i < n) {
        if (ePrimo(v, i, num)) {
            v[i] = num;
            i += 1;
        }
        num += 1;
    }
}

void somatorio(int s[], int a[], int b[], int n) {
    int ib = n - 1;
    for (int i = 0; i < n; i += 1) {
        s[i] = a[i] + b[ib];
        ib -= 1;
    }
}