#include <stdio.h>

typedef struct {
    int hora;
    int minutos;
    int segundos;
} Horario;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    Data data;
    Horario horario;
    char texto[100];
} Compromisso;

int main() {

    Compromisso c;

    printf("Digite a data (dia mes ano): ");
    scanf("%d %d %d", &c.data.dia, &c.data.mes, &c.data.ano);

    printf("Digite o horario (hora minutos segundos): ");
    scanf("%d %d %d", &c.horario.hora, &c.horario.minutos, &c.horario.segundos);

    printf("Digite o compromisso: ");
    scanf(" %[^\n]", c.texto);

    printf("\nCompromisso cadastrado:\n");
    printf("Data: %02d/%02d/%04d\n",
           c.data.dia, c.data.mes, c.data.ano);

    printf("Horario: %02d:%02d:%02d\n",
           c.horario.hora, c.horario.minutos, c.horario.segundos);

    printf("Descricao: %s\n", c.texto);

    return 0;
}