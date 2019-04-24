#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"

void split(list l, list *lu, list *ll, element pivot){
	while (!empty(l)){
		if (head(l) < pivot){
			*ll = cons(head(l), *ll);
		}
		else{
			*lu = cons(head(l), *lu);
		}
		l = tail(l);
	}
}

void main(){
	list l = emptylist();
	FILE *f = fopen("voti.txt", "rt");
	if (f == NULL){
		abort();
	}
	element c;
	while (fscanf(f, " %d", &c)!=EOF){
		l = cons(c, l);
	}
	element pivot;
	printf("Inserisci valore soglia:\n");
	scanf(" %d",&pivot);
	list up = emptylist(), down = emptylist();
	split(l, &up, &down, pivot);
	printf("Valori maggiori o uguali a %d:\n", pivot);
	showlist(up);
	printf("Valori minori di %d:\n", pivot);
	showlist(down);
	dealloc(l);
	dealloc(up);
	dealloc(down);
}