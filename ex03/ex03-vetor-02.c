#include <stdio.h>

#define TAM 10

void preencherVetorDigitacao(int v[], int n);
void imprimirVetor(int v[], int n);

int main() {
    int opcao, num, posA, posB, tamA = TAM, tamb = TAM;
    int va[TAM], vb[TAM];
    printf("==== Preenchimento do Vetor A ====\n");
    preencherVetorDigitacao(va, TAM);
    printf("==== Preenchimento do Vetor B ====\n");
    preencherVetorDigitacao(vb, TAM);
    do {
        printf("MENU/\n");
        printf("1 - Imprimir os dois vetores\n");
        printf("2 - Buscar um valor nos dois vetores\n");
        printf("3 - Achar o maior elemendo dos dois vetores\n");
        printf("4 - Remover um valor do vetor A\n");
        printf("5 - Remover um valor do vetor B\n");
        printf("Digite sua opção (0 para sair): \n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: 
                printf("A = ");
                imprimirVetor(va, TAM);
                printf("B = ");
                imprimirVetor(vb, TAM);
                break; 
            case 2: 
                printf("Digite um valor a ser buscado: ");
                scanf("%d", &num);
                posA = buscaSequencial(va, TAM, num);
                if (posA != -1) {
                    printf("O número %d está na posição %d do vetor A\n", num, posA + 1);
                } else {
                    printf("O valor %d não foi encontrado no vetor A\n", num);
                }
                posB = buscaSequencial(vb, TAM, num);
                if (posB != -1) {
                    printf("O número %d está na posição %d do vetor B\n", num, posB + 1);
                } else {
                    printf("O valor %d não foi encontrado no vetor B\n", num);
                }
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    } while(opcao != 0);
    printf("Vetor A = ");
    imprimirVetor(va, TAM);
    printf("Vetor B = ");
    imprimirVetor(vb, TAM);
    return 0;
}

void preencherVetorDigitacao(int v[], int n){
    for(int i = 0; i < n; i += 1){
        printf("Digite o %d valor: ", i + 1);
        scanf("%d", &v[i]);
    }

}

void imprimirVetor(int v[], int n){
    printf("{");
    if(n > 0) {
        printf(" %2d", v[0]);
        for(int i = 1; i < n; i +=1){
            printf(", %d", v[i]);
        }
    }
    printf(" }\n");
}

int posMaiorValor(int v[], int n){
    int maior = 0;
    for(int i = 1; i < n; i += 1){
        if(v[i] > v[maior]){
            maior = i;
        }
    }
    return maior;
}

int buscaSequencial(int v[], int n, int x){
    for(int i = 0; i < n; i += 1){
        if(v[i] == x){
            return i;
        }
    }
    return -1;
}

//função que remove o valor, deslocando para a esquerda todos os valores posteriores e retorna 1 se removeu, e 0 caso contrário
int removerValor(int v[], int n, int x){
    int pos = buscaSequencial(v, n, x);
    if(pos == -1){
        return 0;
    }
    for(int i = pos + 1; i < n; i += 1){
        v[i - 1] = v[i];
    }
    return 1;
}