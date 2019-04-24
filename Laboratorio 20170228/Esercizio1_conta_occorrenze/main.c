/*Scrivere un programma che, letta come input da linea di comando una stringa e due carattteri diversi, conti le occorrenze dei caratteri nella stringa e restituisca quale carattere appare più volte*/
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]){

	size_t i = 0, c1=0, c2=0;


	while (argv[1][i] != 0){
		if (argv[1][i]==argv[2][0]){
			c1++;
		}
		if (argv[1][i] == argv[3][0]){
			c2++;
		}
			i++;
	}


	if (c1 > c2){
		printf("%d", c1);
	}
	else{
		printf("%d", c2);
	}

	return 0;
}