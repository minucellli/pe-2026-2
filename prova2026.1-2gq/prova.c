#include <stdio.h>
#include <string.h>

//questao 1
void cadastraConta(struct Conta v[], int *tam)
{
    struct Conta nova;

    if (*tam >= TAM_CONTAS)
    {
        printf("Vetor de contas cheio!\n");
        return;
    }

    printf("Digite o ID da conta: ");
    scanf("%d", &nova.id);

    if (buscaId(v, *tam, nova.id) != -1)
    {
        printf("ID ja cadastrado!\n");
        return;
    }

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", nova.cliente);

    printf("Digite o limite: ");
    scanf("%lf", &nova.limite);

    if (nova.limite < 0)
    {
        printf("Limite invalido!\n");
        return;
    }

    nova.saldo = 0;

    v[*tam] = nova;
    (*tam)++;

    printf("Conta cadastrada com sucesso!\n");
}

//questao 2

int buscaBinariaNome(struct Conta v[], int tam, char x[])
{
    int inicio = 0;
    int fim = tam - 1;
    int meio;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (strcmp(v[meio].cliente, x) == 0)
        {
            return meio;
        }
        else if (strcmp(v[meio].cliente, x) < 0)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return -1;
}

//questao 3

void filtraDevedores(struct Conta vContas[], int tamConta,
                     struct Conta vDevedores[], int *tamDevedores)
{
    int i;

    *tamDevedores = 0;

    for (i = 0; i < tamConta; i++)
    {
        if (vContas[i].saldo < 0)
        {
            vDevedores[*tamDevedores] = vContas[i];
            (*tamDevedores)++;
        }
    }
}

//questao 4

int realizarSaque(struct Conta vContas[], int tamConta,
                  struct Operacao vOp[], int *tamOp)
{
    int id, pos;
    double valor;

    printf("Digite o ID da conta: ");
    scanf("%d", &id);

    pos = buscaId(vContas, tamConta, id);

    if (pos == -1)
    {
        printf("Conta nao encontrada!\n");
        return 0;
    }

    printf("Digite o valor do saque: ");
    scanf("%lf", &valor);

    if (valor <= 0)
    {
        printf("Valor invalido!\n");
        return 0;
    }

    if (vContas[pos].saldo + vContas[pos].limite < valor)
    {
        printf("Saldo insuficiente!\n");
        return 0;
    }

    if (*tamOp >= TAM_OPERACOES)
    {
        printf("Vetor de operacoes cheio!\n");
        return 0;
    }

    vContas[pos].saldo -= valor;

    vOp[*tamOp].id = *tamOp + 1;
    vOp[*tamOp].idConta = id;
    vOp[*tamOp].tipo = 'S';
    vOp[*tamOp].valor = -valor;

    (*tamOp)++;

    printf("Saque realizado com sucesso!\n");

    return 1;
}

//questao 5

void extrato(struct Conta vContas[], int tamConta,
             struct Operacao vOp[], int tamOp)
{
    int id, pos, i, j;
    int indices[TAM_OPERACOES];
    int qtd = 0;
    int inicio;
    double saldo, soma = 0;

    printf("Digite o ID da conta: ");
    scanf("%d", &id);

    pos = buscaId(vContas, tamConta, id);

    if (pos == -1)
    {
        printf("Conta nao encontrada!\n");
        return;
    }

    for (i = 0; i < tamOp; i++)
    {
        if (vOp[i].idConta == id)
        {
            indices[qtd] = i;
            qtd++;
        }
    }

    inicio = qtd - 5;

    if (inicio < 0)
    {
        inicio = 0;
    }

    for (i = inicio; i < qtd; i++)
    {
        soma += vOp[indices[i]].valor;
    }

    saldo = vContas[pos].saldo - soma;

    printf("\nCONTA N.%03d\n", id);
    printf("CLIENTE: %s\n", vContas[pos].cliente);

    printf("\nID | OPERACAO | VALOR | SALDO\n");

    printf("Saldo Anterior: %.2f\n", saldo);

    for (i = inicio; i < qtd; i++)
    {
        j = indices[i];

        if (vOp[j].tipo == 'D')
        {
            printf("%04d | Deposito | ", vOp[j].id);
        }
        else if (vOp[j].tipo == 'S')
        {
            printf("%04d | Saque | ", vOp[j].id);
        }
        else if (vOp[j].tipo == 'T')
        {
            printf("%04d | Transferencia | ", vOp[j].id);
        }

        if (vOp[j].valor >= 0)
        {
            saldo += vOp[j].valor;
            printf("%.2f C | ", vOp[j].valor);
        }
        else
        {
            saldo += vOp[j].valor;
            printf("%.2f D | ", -vOp[j].valor);
        }

        printf("%.2f\n", saldo);
    }

    printf("\nSaldo Atual: %.2f\n", vContas[pos].saldo);
}
