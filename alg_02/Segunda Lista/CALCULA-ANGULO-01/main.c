#include <stdio.h>
#include <math.h>

double arctan(double x) {
    /* Calcula o arco tangente de x com precisão de 0.0001 usando a série de Taylor. */
    if (fabs(x) > 1) {
        printf("arctan(x) só está definido para valores de x entre -1 e 1.\n");
        return 0;
    }
    
    double result = 0;
    double sign = 1;
    double term = x;
    int k = 1;
    
    while (fabs(term) >= 0.0001) {
        result += sign * term;
        sign *= -1;
        k += 2;
        term = pow(x, k) / k;
    }
    
    return result;
}

double angulo(double x, double y) {
    /* Calcula o ângulo em radianos formado pelo vetor (x, y) e o eixo horizontal. */
    if (x < 0 || y < 0) {
        printf("As coordenadas x e y devem ser maiores ou iguais a zero.\n");
        return 0;
    }
    
    double r = sqrt(x * x + y * y);
    double theta = arctan(y / x);
    
    if (x < 0) {
        theta += 3.14;
    }
    
    return theta;
}

void le_coordenadas(double *x, double *y) {
    printf("Digite as coordenadas x e y: ");
    scanf("%lf %lf", x, y);
}

int main() {
    double x, y;
    le_coordenadas(&x, &y);
    printf("O ângulo em radianos é: %f\n", angulo(x, y));
    return 0;
}
