#include <stdio.h>

#define TAM 15

void imprimirVetor(int v[], int n);
void preencherPares(int v[], int n);
void preencherPrimos(int v[], int n);
void somatorio(int s[], int a[], int b[],  int n);

int main() {
    int pares[TAM], primos[TAM], soma[TAM];
    preencherPares(pares, TAM);
    /*primeiro vetor*/
    printf("Vetor de Pares:\n");
    imprimirVetor(pares, TAM);
    return 0;
}
void preencherPares(int v[], int n) {
    for (int i = 0;  i < n; i+= 1) {
        v[i] = 102 + (2 * i); 
    }
}

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void preencherPrimos(int v[], int n) {
    int i = 1, num = 3;
    v[0] = 2;
    while (i < n){
        
    }
}