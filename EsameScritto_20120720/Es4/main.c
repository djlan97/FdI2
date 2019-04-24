#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>

void funz(element a, element b, list l){
	int stampato = 0;
	while (!empty(l) && !empty(tail(l))){
		list p = l,s=tail(l);

		if (head(p) >= a && head(s) >= a && (head(p) + head(s)) < b){
			if (stampato==0){
				printElement(head(p));
				printf(", ");
				printElement(head(s));
			}
			else{
				printf(", ");
				printElement(head(s));
			}
			stampato = 1;
		}
		else{
			stampato = 0;
		}

		l = tail(l);
	}
}

list insOrd(element e ,list l){
	if (empty(l)){ 
		return cons(e, l);
	}
	list root = l;
	while (!empty(tail(l))){
		l = tail(l);
	}
	list t = malloc(sizeof(item));
	t->next = emptylist();
	t->value = copy(e);
	l->next = t;
	return root;
}

void main(){
	list l = emptylist();
	element e,a,b;
	printf("Inserisci valori lista:\n");
	do{
		e = getElement();
		if (e >= 0){
			l = insOrd(e, l);
		}
	} while (e >= 0);
	showlist(l);
	do{
		printf("Inserisci un valore positivo A:\n");
		a = getElement();
		if (a <= 0){
			printf("Valore non valido riprovare!\n");
		}
	} while (a <= 0);
	do{
		printf("Inserisci un valore positivo B maggiore di A:\n");
		b = getElement();
		if (b <= 0||a>=b){
			printf("Valore non valido riprovare!\n");
		}
	} while (b <= 0 || a >=b );
	funz(a, b, l);
}