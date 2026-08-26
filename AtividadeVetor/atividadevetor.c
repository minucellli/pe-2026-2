#include <stdio.h>

#define total_alunos 30
int main(){
    float nota1[total_alunos];
    float nota2[total_alunos];
    float media[total_alunos];
    float soma_medias = 0.0;
    float media_turma = 0.0;
    int i;

    for (i = 0; i < total_alunos; i++) {
        printf("Aluno %d:\n", i + 1);

        printf("Digite a primeira nota (peso 2): ");
        scanf("%f", &nota1[i]);

        printf("Digite a segunda nota (peso 3): ");
        scanf("%f", &nota2[i]);

        media[i] = (nota1[i] * 2 + nota2[i] * 3)/5.0;

        soma_medias += media[i];
    }

    media_turma = soma_medias / total_alunos;

    printf("\n=====RESULTADO DA TURMA=====\n");
    printf("Media da turma: %.2f\n", media_turma);

    printf("\nAlunos com media acima da media da turma:\n");
    
    int acima_med = 0;
    for (i = 0; i < total_alunos; i++) {
        if (media[i] > media_turma) {
            printf("Aluno %d = Nota 1: %.2f | Nota 2: %.2f | Media: %.2f\n", i + 1, nota1[i], nota2[i], media[i]);
            acima_med ++;
        }
    }

    if (acima_med == 0) {
        printf("Nenhum aluno ficou acima da media da turma.\n");
    }
    return 0;
}