/*#include <stdio.h>
int main(){
    int num, soma = 0, qtd = 0;
    double media;

    printf("Digite um valor inteiro positivo: ");
    scanf("%d", &num);

    while(num > 0 ) {
        qtd += 1;
        soma += num;
        printf("Digite um valor inteiro positivo (<= 0 para finalizar): ");
        scanf("%d", &num);
    }
    if (qtd > 0) {
        media = (double)soma / qtd;
        printf("Foram digitados %d números e a media é %lf", qtd, media);
    } else {
        printf("Nenhum número positivo foi digitado.\n");
    }
    return 0;
} */

#include <stdio.h>

#define QTD_MAX_VALORES 5

int main(){
    int num, soma = 0, qtd = 0;
    int numeros[QTD_MAX_VALORES];
    double media;

    printf("Digite um valor inteiro positivo: ");
    scanf("%d", &num);

    while(num > 0 ) {
        numeros[qtd] = num;
        qtd += 1;
        soma += num;
        printf("Digite um valor inteiro positivo (<= 0 para finalizar): ");
        scanf("%d", &num);
    }
    if (qtd > 0) {
        media = (double)soma / (double) qtd;
        printf("Foram digitados %d números e a media é %lf.\n", qtd, media);
        printf("\n\nTodos os números digitados:\n");
    } else {
        printf("Nenhum número válido foi digitado.\n");
    }
    for (int i = 0; i < QTD_MAX_VALORES; i += 1) {
        printf("números [%d] = %d\n", i + 1, numeros[i]);

}
    return 0;
}