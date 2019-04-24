#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (strcmp(e1.nome,e2.nome)==0);
}

boolean isLess(element e1, element e2){
	return (strcmp(e1.nome, e2.nome) < 0);
}

element copy(element e){
	element el;
	el = e;
	return el;
}

element getElement(){
	element el;
	printf("Nominativo:\t");
	scanf(" %[^\n]", &el.nome);
	printf("\n");
	printf("Indirizzo:\t");
	scanf(" %[^\n]", &el.via);
	printf("\n");
	return el;
}

void printElement(element el){
	printf("Nominativo:\t %s\nIndirizzo:\t%s\n", el.nome,el.via);
}