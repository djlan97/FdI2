#include <stdlib.h>
#include <string.h>
#include <stdio.h>


double fattoriale(double n){

	if (n == 1){
		return 1;
	}
	else{
		return n * fattoriale(n - 1);
	}

}

int main(int argc, char *argv[]){


	double fatt = fattoriale(atoi(argv[1]));
	

	printf("il fattoriale di %d è %d.", atoi(argv[1]), fatt);

	return EXIT_SUCCESS;
}