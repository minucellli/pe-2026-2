#include <stdio.h>

void preencherVetor(int v[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void imprimirVetor(int v[], int n) {
    int i;

    printf("{ ");

    for (i = 0; i < n; i++) {
        printf("%d", v[i]);

        if (i < n - 1) {
            printf(", ");
        }
    }

    printf(" }\n");
}

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n];

    preencherVetor(v, n);

    printf("Vetor: ");
    imprimirVetor(v, n);

    return 0;
}