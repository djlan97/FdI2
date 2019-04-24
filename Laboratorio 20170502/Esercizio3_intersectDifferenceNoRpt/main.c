#include "list.h"

//DEALLOCAZIONE
void dealloc(list l){
	list temp;
	while (!empty(l)) {
		temp = l;
		l = tail(l);
		free(temp);
	}
}

list difference(list l1, list l2){
	list ret = emptylist();
	if (!empty(l1) && !empty(l2)){
		element el;
		while (!empty(l1)){
			el = head(l1);
			if ((!member(el, l2))&&(!member(el,ret))){
				ret = cons(el, ret);
			}
			l1 = tail(l1);
		}
	}
	return ret;
}

list intersect(list l1, list l2){
	list ret = emptylist();
	if (!empty(l1) && !empty(l2)){
		element el;
		while (!empty(l1)){
			el = head(l1);
			if (member(el, l2)&&(!member(el,ret))){
				ret = cons(el, ret);
			}
			l1 = tail(l1);
		}
	}
	return ret;

}

void main(void){
	list l1 = NULL, l2 = NULL;
	element el;
	do{
		printf("\nInserisci valore l1:\t");
		scanf("%d", &el);
		if (el == 0){
			break;
		}
		else{
			l1 = cons(el, l1);
		}
	} while (1);

	do{
		printf("\nInserisci valore l2:\t");
		scanf("%d", &el);
		if (el == 0){
			break;
		}
		else{
			l2 = cons(el, l2);
		}
	} while (1);



	list l3 = intersect(l1, l2);
	if (empty(l3)){
		printf("Nessun elemento in comune tra le due liste.");
	}
	else{
		printf("Gli elementi in comune tra le due iste sono:\t");
		showlist(l3);

		/*printf("Gli elementi in comune tra le due iste sono:\t");
		while (l3 != NULL){
		printf("%d", l3->value);
		l3 = l3->next;
		if (l3 != NULL) printf(", ");
		else printf("\n");
		}*/
	}
	dealloc(l1);
	dealloc(l2);
	dealloc(l3);
}