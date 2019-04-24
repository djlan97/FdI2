#include <stdlib.h>
#include <string.h>

int occorrenze(char *s, char c){
	if (s[0] == 0){
		return 0;
	}
	if(s[0]==c){
		return 1 + occorrenze(s+1, c);
	}
	else{
		return occorrenze(&s[1], c);
	}
	return 0;
}



int main(int argc, char *argv[]){
	int ris = occorrenze(argv[1],argv[2][0]);

	
	return EXIT_SUCCESS;
}