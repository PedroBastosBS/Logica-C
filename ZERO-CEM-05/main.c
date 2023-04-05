#include <string.h>
#include <stdio.h>

int main() {
    int senha, tentativa, contador = 0;
    int min = 0, max = 100;

    printf("Digitar qualquer valor em um intervalo de 0 a 100 como senha: ");
    scanf("%d", &senha);
        
    // não permite o usuario digitar um valor fora do intervalo
    if(senha > max || senha < min){
        printf("Numero Informado fora do intervalo! \n ");
    }

    while(1)
    {
        printf("Coloque um Valor entre %d e %d: ", min, max);
        scanf("%d", &tentativa);
        contador++;
        if(tentativa == senha) {
            printf("Aeeeee, tu tentou %d vezes.", contador);
            break;
        } else if(tentativa < senha){
            printf("Tenta um Valor Maior!!! \n ");
            min = tentativa + 1;
        } else {
            printf("Tenta um Valor Menor \n ");
            max = tentativa - 1;
        }
    }
    return 0;
}