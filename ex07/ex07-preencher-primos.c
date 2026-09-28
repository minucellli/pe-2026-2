#include <stdio.h>

#define TAM 20

void preencherPrimos

int main() {

    int ePrimo(int v[], int tam, int num) {
        for(int i = 0; i < tam; i += 1) {
            if(num % v[i] == 0) {
                return 0;
            }
        }
        return 1;
    }

void preencherPrimos(int v[], int tam) {
    int num = 2. qtdPrimos = 0;
    while(qtdPrimos < tam) {
        if(ePrimo(v, qtdPrimos, num)) {
            v[qtdPrimos] = num;
            qtdPrimos += 1;
        }
        num += 1;
    }
}
}