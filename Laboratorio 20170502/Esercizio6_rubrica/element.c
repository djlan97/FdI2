#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (strcmp(e1.nome, e2.nome) == 0);
}

boolean isLess(element e1, element e2){
	return (strcmp(e1.nome,e2.nome) < 0);
}

element copy(element e){
	element el;
	el = e;
	return el;
}

element getElement(){
	element e;
	printf("\nNome:\t");
	char v[10];
	fscanf(stdin, "%s", v);

	strcpy(e.nome, v);
	char d[25];
	printf("\nIndirizzo:\t");
	fscanf(stdin, "%s", d);
	strcpy(e.indirizzo, d);
	return e;
}

void printElement(element el){
	fprintf(stdout, "\n%s\t%s", el.nome, el.indirizzo);
}