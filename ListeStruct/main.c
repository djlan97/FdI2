#include "list.h"

void main(){
	list l = emptylist();
	element e;

	//INPUT

	FILE *f = fopen("prova.txt", "rt");
	if (f == NULL){
		return;
	}

	while (fscanf(f, " %s %d", e.str, &e.numero) != EOF){
		l = cons(e, l);
	}
	fclose(f);


	do{
		scanf(" %s %d", e.str, &e.numero);
		if (e.numero >= 0){
			l = cons(e, l);
		}
	} while (e.numero >= 0);
}