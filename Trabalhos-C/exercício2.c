#include <stdio.h>
 int main() {
   int resultado = 0;
   int x = 0;
   int i;
    for (i = 1; i <= 100; i++){
    	resultado = x + i;
    	x = resultado;
    	
    	printf("%d\n",resultado);
    }
}