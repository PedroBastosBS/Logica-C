#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMBUSTIVEL 5
#define MAX_NOME 20

typedef struct {
    char nome[MAX_NOME];
    float preco_litro;
    float imposto;
    float quantidade_total;
} Combustivel;

typedef struct {
    Combustivel combustiveis[MAX_COMBUSTIVEL];
} Posto;

float calcular_valor_total(float preco_litro, float quantidade_litros, float imposto) {
    return (preco_litro * quantidade_litros) * (1 + imposto);
}
FILE *arquivo;
FILE *fluxo;

float cupom(float q, float r, float w);
float reservatorio(float i, float x);
void fluxo_caixa(char b, float c, float d, float e);
float x, e, t, tr;


int main() {
    Posto posto;
    int carregar_dados = 0;
    float vlrpg, litros, res;

    // verifica se deseja carregar dados do arquivo
    printf("Deseja carregar os dados do arquivo? \n1 - para sim \n0 - para nao\n"); //'%s'? ()\n", nome_arquivo);
    scanf("%d", &carregar_dados);

    if (carregar_dados) {
    	arquivo = fopen("posto.txt", "r"); // nao tirar daqui

        if (arquivo != NULL) {


			for (int i = 1; i < MAX_COMBUSTIVEL; i++){
				fscanf(arquivo,"%s %f %f %f\n", posto.combustiveis[i].nome, &posto.combustiveis[i].preco_litro, &posto.combustiveis[i].imposto, &posto.combustiveis[i].quantidade_total);

        	}
        	fclose(arquivo);
        }else {
            printf("Erro ao abrir o arquivo!\n");
            //return 1;
        }
    }else {
        // inicializa os dados do posto

        arquivo = fopen("posto.txt", "w");// r,w,a = read, write, append = ler, escrever, alterar

        for (int i = 1; i < MAX_COMBUSTIVEL; i++) {
            printf("________________________________________________________________\n");
            printf("Digite o nome do combustivel %d: ", i);
            scanf("%s", posto.combustiveis[i].nome);
			fprintf(arquivo, "%s ", posto.combustiveis[i].nome);

            printf("Digite o preco por litro do combustivel %d: ", i);
            scanf("%f", &posto.combustiveis[i].preco_litro);
			fprintf(arquivo, "%.2f ", posto.combustiveis[i].preco_litro);

            printf("Digite a porcentagem de imposto do combustivel %d: ", i);
            scanf("%f", &posto.combustiveis[i].imposto);
			fprintf(arquivo, "%.2f ", posto.combustiveis[i].imposto);

            printf("Digite a quantidade total em litros do combustivel %d: ", i);
            scanf("%f", &posto.combustiveis[i].quantidade_total);
			fprintf(arquivo, "%.2f \n", posto.combustiveis[i].quantidade_total);
            printf("________________________________________________________________\n");
		}
        //fclose(arquivo);
    }

//---------------------------------------// exibe as opções de combustível------------------------------------------------------

    system("cls");
    printf("\nCombustiveis disponiveis:\n");
    for (int i = 1; i < MAX_COMBUSTIVEL; i++) {
        printf("%d. %s (R$ %.2f por litro)\n", i , posto.combustiveis[i].nome, posto.combustiveis[i].preco_litro);
    }
//-----------------------------------// solicita o tipo de combustível desejado--------------------------------

    int opcao_combustivel, vlr_lt;
    printf("\nDigite o numero do combustivel desejado (ou 0 para sair): ");
    scanf("%d", &opcao_combustivel);

    if (opcao_combustivel == 0) {
        printf("Opcao invalida. \n");
		exit(1);// fecha tudo
    }
	else if(opcao_combustivel < 1 || opcao_combustivel > MAX_COMBUSTIVEL)
		printf("Opcao invalida!\n");

	int i = opcao_combustivel;
	printf("\nESCOLHA A OPCAO DESEJADA\n[1]-Valor para abastecimento: \n[2]-Litros para abastecimento: \n");
	scanf("%d", &vlr_lt);





	//printf("%d", vlr_lt);
	if(vlr_lt == 1){
		printf("\nDigite o valor em R$: ");
		scanf("%f", &vlrpg);

        x = vlrpg/posto.combustiveis[i].preco_litro;
        e = (vlrpg * posto.combustiveis[i].imposto)/100;
        t = x * posto.combustiveis[i].preco_litro;
        tr = vlrpg - t;

		res = reservatorio(posto.combustiveis[i].quantidade_total,(vlrpg/posto.combustiveis[i].preco_litro));
		cupom(posto.combustiveis[i].preco_litro, vlrpg,posto.combustiveis[i].imposto);
		printf("Reservatorio: %.2f", res);
		fprintf(arquivo, "%.2f \n", posto.combustiveis[i].quantidade_total)
		//fluxo_caixa(opcao_combustivel, );

	}else
		if(vlr_lt == 2){
			printf("\nDigite o valor em Litros: ");
			scanf("%f", &litros);
			vlrpg = litros * posto.combustiveis[i].preco_litro;
			cupom(posto.combustiveis[i].preco_litro, vlrpg,posto.combustiveis[i].imposto);
			res = reservatorio(posto.combustiveis[i].quantidade_total,(vlrpg/posto.combustiveis[i].preco_litro));
			printf("Reservatorio: %.2f", res);

		}
}
//float calculo(){
//}
float cupom(float q, float r, float w){

	//float x = r / q;
	//float e = (r * w)/100;
	//float t = x * q;
	//float tr = r - t;


	//-------------------------------------------------------------------------
	printf("\n----------CUPOM PARA SIMPLES CONFERENCIA----------");
	printf("\n--------------------------------------------------\n");
	printf("Valor unitario R$:____________________________ %.2f\n", q);
	printf("Litros abastecidos:___________________________ %.2f\n", x);
	printf("Imposto:______________________________________ %.2f\n%", e);
	printf("Valor pago R$:________________________________ %.2f\n", r);
	printf("Total R$:_____________________________________ %.2f\n", t);
	printf("Troco R$:_____________________________________ %.2f\n", tr);
	printf("\n\n--------------------------------------------------\n");
	//fluxo_caixa(z, x, r, m;

}
void fluxo_caixa(char b, float c, float d, float e){
	fluxo = fopen("fluxo.txt", "w");// r,w,a = read, write, append = ler, escrever, alterar

	fprintf(fluxo, "Bomba: %s\n", b);
	fprintf(fluxo, "Litros abastecidos: %.2f\n", c);
	fprintf(fluxo, "Valor pago: %.2f\n", d);
	fprintf(fluxo, "Reservatorio: %.2f\n", e);

	fclose(fluxo);
}


float reservatorio(float tnq, float x){

    //arquivo = fopen("posto.txt", "w");// r,w,a = read, write, append = ler, escrever, alterar

	//fseek(arquivo, posicao * sizeof(), SEEK_SET);

	//fclose(arquivo);
	return tnq -= x;
}
