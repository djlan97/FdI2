#include <stdlib.h>
#include <string.h>
int fibonacci(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	else{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}

}
int main(int argc, char *argv[]){


	int ris=fibonacci(8);


	return EXIT_SUCCESS;
}