#include "element.h"

/*DEFINIZIONE*/
boolean isEqual(element e1, element e2){
	return (e1.val == e2.val);
}

boolean isLess(element e1, element e2){
	return (e1.val < e2.val);
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
	printf("%d, %s", el.val,el.str);
}