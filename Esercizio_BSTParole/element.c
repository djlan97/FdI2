#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (strcmp(e1,e2)==0);
}

boolean isLess(element e1, element e2){
	return (strcmp(e1,e2)<0);
}

element copy(element e){
	element el=malloc(sizeof(MAX));
	strcpy(el, e);
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