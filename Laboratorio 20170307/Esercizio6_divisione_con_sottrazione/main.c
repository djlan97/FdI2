#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int divisione(int n, int m){
	if (n<m||m==0){
		return 0;
	}
	else{
		return 1 + divisione(n-m, m);
	}

}

int main(int argc, char *argv[]){

	if (argc != 3){
		printf("Inserire 2 valori");
		return EXIT_FAILURE;
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	

	if (n < m){
		int tmp=n;
		n = m;
		m = tmp;
	}

	int ris = divisione(n, m);
	printf("Il risultato della divisione %d : %d e' %d",n,m, ris);

	return EXIT_SUCCESS;
}