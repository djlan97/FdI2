#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"

list intersect(list l1, list l2){
	list l3 = emptylist();
	while (!empty(l1) && !empty(l2)){
		if (member(head(l1), l2)){
			l3 = cons(head(l1), l3);
		}
		l1 = tail(l1);
	}

	return l3;
}

list intersect_Norpt(list l1, list l2){
	list l3 = emptylist();
	while (!empty(l1) && !empty(l2)){
		if (member(head(l1), l2)&&!member(head(l1),l3)){
			l3 = cons(head(l1), l3);
		}
		l1 = tail(l1);
	}

	return l3;
}

list difference(list l1, list l2){
	list l3 = emptylist();
	while (!empty(l1) && !empty(l2)){
		if (!member(head(l1), l2)){
			l3 = cons(head(l1), l3);
		}
		l1 = tail(l1);
	}
	return l3;
}

list difference_Norpt(list l1, list l2){
	list l3 = emptylist();
	while (!empty(l1) && !empty(l2)){
		if (!member(head(l1), l2)&&!member(head(l1),l3)){
			l3 = cons(head(l1), l3);
		}
		l1 = tail(l1);
	}
	return l3;
}

element maxelement(list l){
	element max = 0;

	while (!empty(l)){
		if (head(l) > max){
			max = head(l);
		}
		l = tail(l);
	}

	return max;
}

void main(){
	list l1 = emptylist(), l2 = emptylist();
	printf("Inserisci alementi lista 1:\n");
	element c;
	do{
		scanf(" %d", &c);
		if (c!=0){
			l1 = cons(c, l1);
		}
	} while(c != 0);

	showlist(l1);

	printf("Inserisci alementi lista 2:\n");

	do{
		scanf(" %d", &c);
		if (c != 0){
			l2 = cons(c, l2);
		}
	} while (c != 0);

	showlist(l2);

	list l3 = intersect_Norpt(l1, l2);
	printf("Lista intersect:\n");
	showlist(l3);
	l3 = difference_Norpt(l1, l2);
	printf("Lista difference:\n");
	showlist(l3);

	element max = maxelement(l1);
	printf("L'elemento massimo è ");
	printElement(max);
	dealloc(l3);
	dealloc(l1);
	dealloc(l2);
}