#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void ciframais(char x[], int y);
void ciframenos(char x[], int y);

int main(){
	setlocale(LC_ALL,"");
	char palavra[30] = {"Ex 3 lista2"};
	int chave, lado, cod;
	
	printf("Digite o texto: ");
	scanf("%30[^\n]", palavra);
	//printf("%s \n", palavra);

	printf("\n-Codifica��o de C�sar: \n-Decodifica��o de C�sar: \n");
	printf("Digite [1] para codificar e [2] para decodificar: ");
    scanf("%d", &cod);

    printf("\nDigite a chave: ");
    scanf("%d", &chave);

    printf("Digite [1] para a encriptar � direita, e [2] para a encriptar � esquerda: ");
    scanf("%d", &lado);
    
    switch(cod){
		case 1:
			ciframais(palavra, chave);
			break;
		case 2:	
			ciframenos(palavra, chave);
			break;			
	}
    system("pause");	
	return 0;	
}

void ciframais(char x[], int y){
	int i = 0;
	char j[20];	
    while(x[i] != '\0'){
        j[i] = x[i] + y;
    i++;
	}
	printf("\nTexo encriptado: %s.\n",j);
}
void ciframenos(char x[], int y){
	int i = 0;
	char j[20];	
    while(x[i] != '\0'){
        j[i] = x[i] - y;
    i++;
	}
	printf("\nTexto encriptado: %s.\n",j);
}


