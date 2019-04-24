#include "list.h"

void main(){
	list l = emptylist();
	element e;

	//INPUT

	FILE *f = fopen("prova.txt", "rt");
	if (f == NULL){
		return;
	}
	
	while (fscanf(f, " %d", &e)!=EOF){
		l = cons(e, l);
	}
	fclose(f);


	do{
		scanf(" %d", &e);
		if (e >= 0){
			l = cons(e, l);
		}
	} while (e >= 0);

}