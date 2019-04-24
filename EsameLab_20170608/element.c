#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (strcmp(e1.matricola,e2.matricola)==0);
}

boolean isLess(element e1, element e2){
	return (strcmp(e1.matricola, e2.matricola) < 0);
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
	printf("%d", el);
}