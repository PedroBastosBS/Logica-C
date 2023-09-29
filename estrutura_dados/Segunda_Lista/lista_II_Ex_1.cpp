#include <stdio.h>

void torreHanoi(int n, char origem, char auxiliar, char destino) {
    if (n == 1) {
        printf("Mova o disco 1 de %c para %c\n", origem, destino);
        return;
    }
    
    torreHanoi(n - 1, origem, destino, auxiliar);
    printf("Mova o disco %d de %c para %c\n", n, origem, destino);
    torreHanoi(n - 1, auxiliar, origem, destino);
}

int main() {
    int n;
    
    printf("Quantos discos na Torre de Hanói? ");
    scanf("%d", &n);
    
    torreHanoi(n, 'O', 'A', 'D');
    
    return 0;
}