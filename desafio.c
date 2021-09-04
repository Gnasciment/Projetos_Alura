#include <stdio.h>
void main()
{


	printf("Digite um numero inteiro\n");
	int x;
	int y;
	int resultado;
	scanf("%d", &x);

	printf("digite outro numero inteiro \n");
	scanf("%d",&y);

	resultado = x*y;
	printf("O resultado e %d", resultado);
}