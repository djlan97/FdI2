#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (strcmp(e1.nome, e2.nome)==0);
}

boolean isLess(element e1, element e2){
	return (strcmp(e1.nome, e2.nome)< 0);
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
	printf("%s %d", el.nome,el.interessi);
}