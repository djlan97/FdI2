#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (e1.nome == e2.nome);
}

boolean isLess(element e1, element e2){
	return (e1.nome < e2.nome);
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