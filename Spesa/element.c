#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (strcmp(e1.nome,e2.nome)==0);
}

boolean isLess(element e1, element e2){
	return (e1.quantita < e2.quantita);
}

element copy(element e){
	element el;
	el = e;
	return el;
}

element getElement(){
	element el;
	printf("Articolo:\t");
	scanf(" %[^\n]", el.nome);
	printf("\n");
	printf("Quantità:\t");
	scanf(" %f", &el.quantita);
	printf("\n");
	printf("Unità di misura:\t");
	scanf(" %[^\n]", el.misura);
	printf("\n");
	return el;
}

void printElement(element el){
	printf("Articolo:\t%s\n",el.nome);
	printf("Quantità:\t%f\n", el.quantita);
	printf("Unità di misura:\t%s\n", el.misura);
}