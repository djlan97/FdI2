#include "tree.h"

void main(){
	tree l = emptyTree();
	element e;

	//INPUT

	FILE *f = fopen("prova.txt", "rt");
	if (f == NULL){
		return;
	}

	while (fscanf(f, " %s %d", e.str, &e.numero) != EOF){
		l = insertBinOrd(e, l);
	}
	fclose(f);


	do{
		scanf(" %s %d", e.str, &e.numero);
		if (e.numero >= 0){
			l = insertBinOrd(e, l);
		}
	} while (e.numero >= 0);
}