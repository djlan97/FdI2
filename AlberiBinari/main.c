#include "tree.h"

void main(){
	tree l = emptyTree();
	element e;

	//INPUT

	FILE *f = fopen("prova.txt", "rt");
	if (f == NULL){
		return;
	}

	while (fscanf(f, " %d", &e) != EOF){
		l = insertBinOrd(e, l);
	}
	fclose(f);


	do{
		scanf(" %d", &e);
		if (e >= 0){
			l = insertBinOrd(e, l);
		}
	} while (e >= 0);
}