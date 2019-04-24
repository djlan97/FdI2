#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int prodotto(int n, int m){

	if (m == 1){
		return n;
	}
	else{
		return n + prodotto(n, m-1);
	}

}

int main(int argc, char *argv[]){

	int somma = prodotto(atoi(argv[1]), atoi(argv[2]));
	printf("Il prodotto di %d e %d è %d.", atoi(argv[1]), atoi(argv[2]), somma);

	return EXIT_SUCCESS;
}