#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (strcmp(e1.dominio,e2.dominio)==0);
}

boolean isLess(element e1, element e2){
	return (strcmp(e1.dominio,e2.dominio)<0);
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
	printf("%s\t%d\n", el.dominio,el.accessi);
}