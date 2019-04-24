#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (strcmp(e1.str, e2.str) == 0);
}

boolean isLess(element e1, element e2){
	return (strcmp(e1.str, e2.str) < 0);
}

element copy(element e){
	element el;
	el = e;
	return el;
}

element getElement(){
	element el;
	scanf(" %s %d", el.str, &el.numero);
	return el;
}

void printElement(element el){
	printf("%s %d", el.str, el.numero);
}