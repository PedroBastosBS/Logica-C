#include <stdio.h>

int main() {
    int a, b, c;

    printf("Numeros de Pitagoras:\n");
    printf("Cateto 1  |  Cateto 2  |  Hipotenusa\n");
    printf("--------------------------------------\n");

    for (a = 1; a < 500; a++) {
        for (b = 1; b < 500; b++) {
            for (c = 1; c < 500; c++) {
                if (a*a + b*b == c*c) {
                    printf("%9d  |  %9d  |  %10d\n", a, b, c);
                }
            }
        }
    }

    return 0;
}
