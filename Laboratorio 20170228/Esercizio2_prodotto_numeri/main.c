#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	int p = 1;

	for (int i = 1; i <= argc - 1; ++i){
		p*=atoi(argv[i]);
	}

	printf("%d",p);

	return 0;
}