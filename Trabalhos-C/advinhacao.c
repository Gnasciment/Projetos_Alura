#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {

	// imprime o cabecalho do nosso jogo
	printf("*******************************************\n");
	printf("***Bem vindo ao nosso jogo de advinhacao***\n");
	printf("*******************************************\n");

	int segundos = time(0);
	srand(segundos);
	
	int numerogrande = rand() ;

	int numerosecreto =  numerogrande % 100;
	int chute = 0;
	int tentativas = 1;
	
	double pontos = 1000.0;

	int acertou = 1;

	int nivel;
	printf("Qual o nivel voce prefere\n");
	printf("(1) facil, (2) medio, (3)dificil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);

	int numerosdetentativas;
	
	switch(nivel){
		case 1:
		numerosdetentativas = 15;
		break;

		case 2:
		numerosdetentativas = 10;
		break;

		case 3:
		numerosdetentativas = 5;
		break;
	}


	for( int i = 1; i <= numerosdetentativas; i++){

		printf("Tentativa %d\n", tentativas);
		printf("qual e o seu chute? ");

		scanf("%d", &chute);
		printf("Seu chute foi %d \n", chute);

		if(chute < 0){
			printf("Voce nao pode chutar numeros negativos\n");
					
			continue;
		}

		int  acertou = (chute == numerosecreto);
		int  maior = (chute > numerosecreto);

		if(acertou){
			break;
		}
		
		else if(maior){
			printf("Seu chute foi maior do que o numero secreto \n");
		}

		else{
			printf("Seu chute foi menor que o numero secreto \n");
		}

		tentativas++;

		double pontosperdidos = abs(chute - numerosecreto) / (double)2;
		pontos = pontos - pontosperdidos;
	}
		printf ("Fim de jogo!\n");
	if(acertou){
		printf("Parabens voce acertou\n");
		printf("voce ganhou depois de %d tentativas\n", tentativas );
		printf("Total de pontos : %.1f\n", pontos);
	}
	else{
		printf("Voce perdeu! Tente Novamente\n");
	}
}