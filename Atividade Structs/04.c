#include <stdio.h>
#include <math.h>

struct Polar {
    double r;
    double a;
};

struct Cartesiana {
    double x;
    double y;
};

int main() {

    struct Polar polar;
    struct Cartesiana cartesiana;

    printf("Digite o raio: ");
    scanf("%lf", &polar.r);

    printf("Digite o angulo em radianos: ");
    scanf("%lf", &polar.a);

    cartesiana.x = polar.r * cos(polar.a);
    cartesiana.y = polar.r * sin(polar.a);

    printf("\nCoordenada cartesiana:\n");
    printf("x = %.2lf\n", cartesiana.x);
    printf("y = %.2lf\n", cartesiana.y);

    return 0;
}