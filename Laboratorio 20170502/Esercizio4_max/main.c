#include "list.h"

element max_l(list l){
	element max = 0;

	while (!empty(l)){
		element el = head(l);
		if (el > max){
			max = el;
		}
		l = tail(l);
	}

	return max;
}


void main(void){
	list l1 = emptylist();
	element max=0;
	element el;
	do{
		printf("\nInserisci valore :\t");
		scanf("%d", &el);
		if (el == 0){
			break;
		}
		else{
			l1 = cons(el, l1);
		}
	} while (1);

	max = max_l(l1);
	printf("L'elemento massimo è %d", max);
	dealloc(l1);
}