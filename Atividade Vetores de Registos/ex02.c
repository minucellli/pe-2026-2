#include <stdio.h>

#define MAX 100

typedef struct {
    int numero;
    char nome[100];
    char cpf[15];
    char telefone[20];
    float saldo;
} Conta;

int buscar(Conta c[], int total, int numero) {
    if (total == 0)
        return -1;

    for (int i = 0; i < total; i++) {
        if (c[i].numero == numero)
            return i;
    }

    return -2;
}

void cadastrar(Conta c[], int *total, int numero) {
    if (*total >= MAX) {
        printf("Cadastro cheio!\n");
        return;
    }

    if (buscar(c, *total, numero) != -2) {
        printf("Numero de conta ja cadastrado!\n");
        return;
    }

    c[*total].numero = numero;

    printf("Nome: ");
    scanf(" %[^\n]", c[*total].nome);

    printf("CPF: ");
    scanf("%s", c[*total].cpf);

    printf("Telefone: ");
    scanf("%s", c[*total].telefone);

    printf("Saldo inicial: ");
    scanf("%f", &c[*total].saldo);

    (*total)++;

    printf("Conta cadastrada com sucesso!\n");
}

void consultarSaldo(Conta c[], int total, int numero) {
    int pos = buscar(c, total, numero);

    if (pos >= 0)
        printf("Saldo: R$ %.2f\n", c[pos].saldo);
    else
        printf("Conta nao cadastrada!\n");
}

void depositar(Conta c[], int total, int numero) {
    int pos = buscar(c, total, numero);
    float valor;

    if (pos == -1 || pos == -2) {
        printf("Conta nao cadastrada!\n");
        return;
    }

    printf("Valor do deposito: ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("Valor invalido!\n");
        return;
    }

    c[pos].saldo += valor;

    printf("Deposito realizado!\n");
}

void sacar(Conta c[], int total, int numero) {
    int pos = buscar(c, total, numero);
    float valor;

    if (pos == -1 || pos == -2) {
        printf("Conta nao cadastrada!\n");
        return;
    }

    printf("Valor do saque: ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("Valor invalido!\n");
        return;
    }

    if (c[pos].saldo >= valor) {
        c[pos].saldo -= valor;
        printf("Saque realizado!\n");
    } else {
        printf("Saldo insuficiente!\n");
    }
}

void exibirContas(Conta c[], int total) {
    if (total == 0) {
        printf("Nenhuma conta cadastrada!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\nNumero: %d\n", c[i].numero);
        printf("Nome: %s\n", c[i].nome);
        printf("Telefone: %s\n", c[i].telefone);
    }
}

int main() {
    Conta corrente[MAX], poupanca[MAX];

    int totalCorrente = 0;
    int totalPoupanca = 0;

    int opcao, tipo, numero;

    do {
        printf("\n--- BANCO DINHEIRO CERTO ---\n");
        printf("1 - Cadastrar conta\n");
        printf("2 - Consultar saldo\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5 - Exibir contas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 5) {
            printf("\n1 - Conta corrente\n");
            printf("2 - Conta poupanca\n");
            printf("Tipo de conta: ");
            scanf("%d", &tipo);

            if (tipo == 1) {
                switch (opcao) {
                    case 1:
                        printf("Numero da conta: ");
                        scanf("%d", &numero);
                        cadastrar(corrente, &totalCorrente, numero);
                        break;

                    case 2:
                        printf("Numero da conta: ");
                        scanf("%d", &numero);
                        consultarSaldo(corrente, totalCorrente, numero);
                        break;

                    case 3:
                        printf("Numero da conta: ");
                        scanf("%d", &numero);
                        depositar(corrente, totalCorrente, numero);
                        break;

                    case 4:
                        printf("Numero da conta: ");
                        scanf("%d", &numero);
                        sacar(corrente, totalCorrente, numero);
                        break;

                    case 5:
                        exibirContas(corrente, totalCorrente);
                        break;
                }
            } else if (tipo == 2) {
                switch (opcao) {
                    case 1:
                        printf("Numero da conta: ");
                        scanf("%d", &numero);
                        cadastrar(poupanca, &totalPoupanca, numero);
                        break;

                    case 2:
                        printf("Numero da conta: ");
                        scanf("%d", &numero);
                        consultarSaldo(poupanca, totalPoupanca, numero);
                        break;

                    case 3:
                        printf("Numero da conta: ");
                        scanf("%d", &numero);
                        depositar(poupanca, totalPoupanca, numero);
                        break;

                    case 4:
                        printf("Numero da conta: ");
                        scanf("%d", &numero);
                        sacar(poupanca, totalPoupanca, numero);
                        break;

                    case 5:
                        exibirContas(poupanca, totalPoupanca);
                        break;
                }
            } else {
                printf("Tipo de conta invalido!\n");
            }
        }

    } while (opcao != 0);

    return 0;
}
