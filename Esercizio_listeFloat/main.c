#include "list.h"

list insCoda(element e, list l){
	if (empty(l)){ 
		return cons(e, l); 
	}

	list root = l;
	while (!empty(tail(l))){
		l = tail(l);
	}

	list t = (list)malloc(sizeof(item));
	t->value = copy(e);
	t->next = emptylist();
	l->next = t;
	return root;
}

void funz(element a, element b, list l){
	list prec = l;
	bool stampato = false;

	while (!empty(prec)&&!empty(tail(prec))){
		l = tail(prec);
		if (head(prec) >= a && head(l) >= a && head(prec) + head(l) < b){
			if (stampato == false){
				printElement(head(prec));
			}
			printElement(head(l));
			stampato = true;			
		}
		else{
			stampato = false;
		}
		prec = tail(prec);
	}
}

void main(){
	list l = emptylist();
	element e, a, b;
	do{
		printf("\nInserisci valore lista:\t");
		e = getElement();
		if (e>=0){
			l = insCoda(e, l);
		}
	} while (e >= 0);

	do{
		printf("\nInserisci primo valore:\t");
		a = getElement();
		printf("\nInserisci secondo valore:\t");
		b = getElement();
		if (!(a > 0 && b > 0 && b > a)){
			printf("\nVALORI NON VALIDI!");
		}
	} while (!(a > 0 && b > 0 && b > a));

	funz(a, b, l);
}