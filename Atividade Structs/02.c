#include <stdio.h>

struct Pessoa {
    char nome[100];
    int idade;
    char endereco[200];
};

int main() {

    struct Pessoa pessoa;

    printf("Digite o nome: ");
    scanf(" %[^\n]", pessoa.nome);

    printf("Digite a idade: ");
    scanf("%d", &pessoa.idade);

    printf("Digite o endereco: ");
    scanf(" %[^\n]", pessoa.endereco);

    printf("\nDados da pessoa:\n");
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d anos\n", pessoa.idade);
    printf("Endereco: %s\n", pessoa.endereco);

    return 0;
}