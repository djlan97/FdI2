#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int sommaNnumeri(int n){
	
	if (n == 1){
		return 1;
	}
	else{
		return n+sommaNnumeri(n - 1);
	}

}

int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	if (n < 1){
		printf("ERRORE: Inserire un numero maggiore o uguale a 1!");
		return EXIT_SUCCESS;
	}
	int somma = sommaNnumeri(n);

	printf("La somma dei primi %d numeri positivi e' %d.", n, somma);

	return EXIT_SUCCESS;
}