#include <stdio.h>

struct Vetor {
    double x;
    double y;
    double z;
};

int main() {

    struct Vetor v1, v2, soma;

    printf("Digite x, y e z do primeiro vetor: ");
    scanf("%lf %lf %lf", &v1.x, &v1.y, &v1.z);

    printf("Digite x, y e z do segundo vetor: ");
    scanf("%lf %lf %lf", &v2.x, &v2.y, &v2.z);

    soma.x = v1.x + v2.x;
    soma.y = v1.y + v2.y;
    soma.z = v1.z + v2.z;

    printf("\nSoma dos vetores:\n");
    printf("x = %.2lf\n", soma.x);
    printf("y = %.2lf\n", soma.y);
    printf("z = %.2lf\n", soma.z);

    return 0;
}