#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (strcmp(e1.prodotto,e2.prodotto)==0);
}

boolean isLess(element e1, element e2){
	return (strcmp(e1.prodotto, e2.prodotto) < 0);
}

element copy(element e){
	element el;
	el = e;
	return el;
}

element getElement(){
	element el;
	printf("prodotto:");
	scanf(" %s", el.prodotto);
	printf("quantità:");
	scanf(" %d", &el.quantita);
	printf("unità di misura:");
	scanf(" %s", el.misura);
	return el;
}

void printElement(element el){
	printf("\n%s, %d, %s\n", el.prodotto,el.quantita,el.misura);
}