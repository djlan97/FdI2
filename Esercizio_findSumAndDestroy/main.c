#include "list.h"

list seekAndDestroy(list l,int k){
	list root = l, prec = l;
	while (!empty(prec)){
		l = tail(l);
		int sum = prec->value;

		//Costo maggiore perchè somma fino alla fine della lista

		while (!empty(l)){
			sum += l->value;
			if (sum == k){
				*prec = *tail(l); //fondamentale * per cambire il value altrimenti diresti solo che prec punta ad un altro punto della lista senza cambiare value e *next!!
				return root;
			}
			l = tail(l);
		}
		prec = tail(prec);
		l = prec;
	}
	return root;
}


list* findSumAndDestroy2(list *l, int k){
	list prec = *l;
	list sump = emptylist();
	while (!empty(prec)){
		int somma = prec->value;
		sump = tail(prec);
		while (!empty(sump) && somma < k){
			somma += sump->value;
			sump = tail(sump);
		}
		if (somma == k){
			
			*prec = *sump;
			
			return l;
		}
		else{
			prec = tail(prec);
		}
	}

	return l;

}



list findSumAndDestroy(list l, int k){
	list prec = l;
	list sump = emptylist();
	while (!empty(prec)){
		int somma = prec->value;
		sump = tail(prec);
		while (!empty(sump) && somma < k){
			somma += sump->value;
			sump = tail(sump);
		}
		if (somma == k){
			prec->next = sump->next; prec->value = sump->value;	// *prec = *sump ; 
			return l;
		}
		else{
			prec = tail(prec);
		}
	}

	return l;
	
}

list findSumAndDestroyHElement(list l,int k,int h){
	list prec = l;
	list sump = emptylist();
	while (!empty(prec)){
		int somma = prec->value, count=1;
		sump = tail(prec);
		while (!empty(sump) && somma < k && count < h){
			somma += sump->value;
			++count;
			sump = tail(sump);
		}
		if (somma == k && count == h){
			prec->next = sump->next; prec->value = sump->value;	/* *prec = *sump; */
			return l;
		}
		else{
			prec = tail(prec);
		}
	}

	return l;
}

void main(){
	list l = emptylist();
	l = cons(9, l);
	l = cons(2, l);
	l = cons(8, l);
	l = cons(5, l);
	l = cons(3, l);
	//list f = seekAndDestroy(l, 15);
	list *t = findSumAndDestroy2(&l, 9);
	showlist(l);
}