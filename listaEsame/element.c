#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (e1.eta == e2.eta);
}

boolean isLess(element e1, element e2){
	return (e1.eta < e2.eta);
}

element copy(element e){
	element el;
	el = e;
	return el;
}

element getElement(){
	element el;
	scanf("%d", &el);
	return el;
}

void printElement(element el){
	printf(" %s %s %d %d", el.cognome,el.nome,el.eta,el.id);
}