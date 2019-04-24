#include "list.h"

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
			if (!member(el, l2)){
				ret = cons(el, ret);
			}
			l1 = tail(l1);
		}
	}
	return ret;
}

/*list difference(list l1, list l2){
	list ret = NULL;
	if (!empty(l1) && !empty(l2)){		
		list  list1 = l1, list2 = l2;
		while (!empty(l1)){
			boolean find = false;
			while (!empty(list2)){
				if (isEqual(l1->value, list2->value)){
					find = true;
					break;
				}
				else{
					list2 = list2->next;
				}
			}
			if (!find){
				ret = cons(l1->value, ret);
			}
			list2 = l2;
			l1 = l1->next;
		}
	}
	return ret;
}*/


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



	list l3 = difference(l1, l2);
	if (empty(l3)){
		printf("Le due liste contengono gli stessi elementi.");
	}
	else{
		printf("Gli elementi non in comune tra le due iste sono:\t");
		showlist(l3);
		/*while (l3 != NULL){
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