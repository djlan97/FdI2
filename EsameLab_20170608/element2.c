#include "element2.h"

/*DEFINIZIONE*/
boolean isEqual2(element2 e1, element2 e2){
	return (e1 == e2);
}

boolean isLess2(element2 e1, element2 e2){
	return (e1 < e2);
}

element2 copy2(element2 e){
	element2 el;
	el = e;
	return el;
}

element2 getelement2(){
	element2 el;
	scanf("%d", &el);
	return el;
}

void printelement2(element2 el){
	printf("%d", el);
}