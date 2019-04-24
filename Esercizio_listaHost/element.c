#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (e1.accessi == e2.accessi);
}

boolean isLess(element e1, element e2){
	return (e1.accessi < e2.accessi);
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
	printf("%s\t%d\n", el.host,el.accessi);
}