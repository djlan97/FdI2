#include "list.h"
#include <stdio.h>

element maxElement(list l){
	element max = 0;
	while (!empty(l)){
		if (head(l) > max){
			max = head(l);
		}
		l = tail(l);
	}

	return max;
}

list leggiVoti(const char *filename){
	list l = emptylist();
	FILE *f = fopen(filename, "rt");
	if (f == NULL){
		return NULL;
	}
	element e;
	while (fscanf(f, " %d", &e) != EOF){
		l = cons(e, l);
	}

	showlist(l);
	return l;
}

void splitList(list l, element pivot){
	list ll = emptylist(), lu = emptylist();
	while (!empty(l)){
		if (head(l) < pivot){
			ll = cons(head(l), ll);
		}
		else{
			lu = cons(head(l), lu);
		}
		l = tail(l);
	}

	showlist(ll);
	showlist(lu);
}

list intersect(list l1, list l2){
	list l3 = emptylist();
	while (!empty(l1)){
		if (member(head(l1), l2)){
			l3 = cons(head(l1), l3);
		}
		l1 = tail(l1);
	}

	return l3;
}

list intersect_noRpt(list l1, list l2){
	list l3 = emptylist();
	while (!empty(l1)){
		if (member(head(l1), l2) && !member(head(l1), l3)){
			l3 = cons(head(l1), l3);
		}
		l1 = tail(l1);
	}

	return l3;
}

list difference(list l1, list l2){
	list l3 = emptylist();
	while (!empty(l1)){
		if (!member(head(l1), l2)){
			l3 = cons(head(l1), l3);
		}
		l1 = tail(l1);
	}
	return l3;
}

list difference_noRpt(list l1, list l2){
	list l3 = emptylist();
	while (!empty(l1)){
		if (!member(head(l1), l2) && !member(head(l1), l3)){
			l3 = cons(head(l1), l3);
		}
		l1 = tail(l1);
	}
	return l3;
}

void main(){

}