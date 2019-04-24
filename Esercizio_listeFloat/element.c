#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (e1 == e2);
}

boolean isLess(element e1, element e2){
	return (e1 < e2);
}

element copy(element e){
	element el;
	el = e;
	return el;
}

element getElement(){
	element el;
	scanf("%f", &el);
	return el;
}

void printElement(element el){
	printf("%f ", el);
}