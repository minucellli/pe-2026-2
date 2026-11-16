#include <stdio.h>
#include <string.h>

#define MAX 40

typedef struct {
    int codigo;
    char descricao[100];
    float valor;
    int estoque;
} Produto;

void cadastrar(Produto p[], int *total) {
    if (*total >= MAX) {
        printf("Cadastro cheio!\n");
        return;
    }

    printf("Codigo: ");
    scanf("%d", &p[*total].codigo);

    printf("Descricao: ");
    scanf(" %[^\n]", p[*total].descricao);

    printf("Valor unitario: ");
    scanf("%f", &p[*total].valor);

    printf("Quantidade em estoque: ");
    scanf("%d", &p[*total].estoque);

    (*total)++;
}

int buscar(Produto p[], int total, int codigo) {
    for (int i = 0; i < total; i++) {
        if (p[i].codigo == codigo)
            return i;
    }
    return -1;
}

void alterarValor(Produto p[], int total, int codigo) {
    int pos = buscar(p, total, codigo);

    if (pos == -1) {
        printf("Produto nao encontrado!\n");
        return;
    }

    printf("Novo valor: ");
    scanf("%f", &p[pos].valor);
}

float consultarValor(Produto p[], int total, int codigo) {
    int pos = buscar(p, total, codigo);

    if (pos == -1)
        return -1;

    return p[pos].valor;
}

int consultarEstoque(Produto p[], int total, int codigo) {
    int pos = buscar(p, total, codigo);

    if (pos == -1)
        return -1;

    return p[pos].estoque;
}

void vender(Produto p[], int total, int codigo, int quantidade) {
    int pos = buscar(p, total, codigo);

    if (pos == -1) {
        printf("Produto nao encontrado!\n");
        return;
    }

    if (p[pos].estoque == 0) {
        printf("Produto sem estoque!\n");
        return;
    }

    if (quantidade <= 0) {
        printf("Quantidade invalida!\n");
        return;
    }

    if (quantidade > p[pos].estoque) {
        int opcao;

        printf("Quantidade desejada maior que o estoque.\n");
        printf("Deseja comprar as %d unidades disponiveis? (1-Sim / 0-Nao): ",
               p[pos].estoque);
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Valor a pagar: R$ %.2f\n",
                   p[pos].estoque * p[pos].valor);
            p[pos].estoque = 0;
        } else {
            printf("Venda cancelada!\n");
        }
    } else {
        printf("Valor a pagar: R$ %.2f\n",
               quantidade * p[pos].valor);

        p[pos].estoque -= quantidade;
    }
}

void atualizarEstoque(Produto p[], int total, int codigo) {
    int pos = buscar(p, total, codigo);

    if (pos == -1) {
        printf("Produto nao encontrado!\n");
        return;
    }

    printf("Nova quantidade em estoque: ");
    scanf("%d", &p[pos].estoque);
}

void exibirTodos(Produto p[], int total) {
    for (int i = 0; i < total; i++) {
        printf("Codigo: %d | Descricao: %s\n",
               p[i].codigo, p[i].descricao);
    }
}

void exibirSemEstoque(Produto p[], int total) {
    for (int i = 0; i < total; i++) {
        if (p[i].estoque == 0) {
            printf("Codigo: %d | Descricao: %s\n",
                   p[i].codigo, p[i].descricao);
        }
    }
}

int main() {
    Produto produtos[MAX];
    int total = 0;
    int opcao, codigo, quantidade;

    do {
        printf("\n--- PAPELARIA ESCOLAR ---\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Alterar valor\n");
        printf("3 - Consultar valor\n");
        printf("4 - Consultar estoque\n");
        printf("5 - Vender produto\n");
        printf("6 - Atualizar estoque\n");
        printf("7 - Exibir todos os produtos\n");
        printf("8 - Exibir produtos sem estoque\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar(produtos, &total);
                break;

            case 2:
                printf("Codigo: ");
                scanf("%d", &codigo);
                alterarValor(produtos, total, codigo);
                break;

            case 3:
                printf("Codigo: ");
                scanf("%d", &codigo);
                printf("Valor: R$ %.2f\n",
                       consultarValor(produtos, total, codigo));
                break;

            case 4:
                printf("Codigo: ");
                scanf("%d", &codigo);
                printf("Estoque: %d\n",
                       consultarEstoque(produtos, total, codigo));
                break;

            case 5:
                printf("Codigo: ");
                scanf("%d", &codigo);
                printf("Quantidade desejada: ");
                scanf("%d", &quantidade);
                vender(produtos, total, codigo, quantidade);
                break;

            case 6:
                printf("Codigo: ");
                scanf("%d", &codigo);
                atualizarEstoque(produtos, total, codigo);
                break;

            case 7:
                exibirTodos(produtos, total);
                break;

            case 8:
                exibirSemEstoque(produtos, total);
                break;
        }

    } while (opcao != 0);

    return 0;
}