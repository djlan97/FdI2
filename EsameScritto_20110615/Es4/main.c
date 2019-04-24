#include "list.h"

void deleteElementBtwn(list l,list inizio, list fine){
	if (l == inizio){
		l = NULL;
	}
	else{
		while (tail(l) != inizio){
			l = tail(l);
		}

		l->next = NULL;
	}

}

list *SeekAndDestroy(list *l, int k){
	list inizio = *l, fine = NULL;
	while (!empty(inizio)){
		int somma = head(inizio);
		fine = tail(inizio);
		while (!empty(fine)&&somma<k){
			somma += head(fine);
			fine = tail(fine);
		}
		if (somma == k){
			if (fine != NULL){
				*inizio = *fine;
			}
			else{
				deleteElementBtwn(*l, inizio, fine);
			}
			return l;
		}
		inizio = tail(inizio);
	}
	return l;
}

/*list *SeekAndDestroy(list *l, int k){
	list prec = *l,succ=emptylist();
	while (!empty(prec)){
		succ = tail(prec);
		int somma = head(prec);
		while (!empty(succ)&&somma<k){
			
			somma += head(succ);
			
			succ = tail(succ);
		}
		if (somma == k){
			deleteElementBtwn(*l, prec, succ);
			return l;
		}
		prec = tail(prec);
	}
	return l;
}
*/
void main(){
	list l = NULL;
	l = cons(3, l);
	l = cons(2, l);
	l = cons(6, l);
	list *t = SeekAndDestroy(&l, 3);
}