#include <stdio.h>
#include <math.h>

double f(double x) {
    return 2 * sin(x) + 3;
}

double largura_intervalo(int n) {
    return (8 - 1) / (double) n;
}

double integral_simpson(double a, double b) {
    double h = (b - a) / 2.0;
    return (h / 3.0) * (f(a) + 4 * f((a + b) / 2.0) + f(b));
}

void calcular_e_salvar_resultados(int n) {
    char filename[20];
    sprintf(filename, "resultados_%d.txt", n);
    FILE *file = fopen(filename, "w");
    if (file) {
        double largura = largura_intervalo(n);
        int num_pontos = (int) ceil((8 - 1) / largura);
        double x = 1;
        double area_total = 0;
        for (int i = 0; i < num_pontos - 1; i++) {
            double a = x;
            double b = x + largura;
            double area = integral_simpson(a, b);
            area_total += area;
            fprintf(file, "%lf %lf\n", x, f(x));
            x += largura;
        }
        fprintf(file, "%lf %lf\n", x, f(x));
        fprintf(file, "num_pontos: %d\n", num_pontos);
        fprintf(file, "area_total: %lf\n", area_total);
        fclose(file);
    }
}

int main() {
    calcular_e_salvar_resultados(10000);
    calcular_e_salvar_resultados(1000);
    calcular_e_salvar_resultados(100);
    calcular_e_salvar_resultados(10);
    calcular_e_salvar_resultados(1);

    return 0;
}
