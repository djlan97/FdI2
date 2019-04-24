#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <string.h>
#include <stdio.h>

void scambia(element *e1, element *e2){
	element tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

list ordinaLista(list l){
	if (empty(l)){
		printf("LISTA VUOTA!");
		return emptylist();
	}
	if (empty(tail(l))){
		return l;
	}
	list root = l;
	bool ordinato = false;
	while (!ordinato){
		ordinato = true;	/* ipotesi: è ordinato */
		while (!empty(tail(l))){
			list succ = tail(l);
			if (!isLess(l->value, succ->value)){
				scambia(&(l->value), &(succ->value));
				ordinato = false;
			}
			l = tail(l);
		}
		l = root;
	}
	return root;
}

void visualizzaMaggiore(list l, float prezzo){
	list t = emptylist();
	while (!empty(l)){
		if (head(l).prezzo > prezzo){
			t = cons(head(l), t);
		}
		l = tail(l);
	}
	t=ordinaLista(t);
	showlist(t);
}

void trovaCoppie(list l, float prezzo){
	while (!empty(l)){
		list succ = tail(l);
		while (!empty(succ)){
			if ((head(l).prezzo + head(succ).prezzo) == prezzo){
				printf("\n");
				printElement(head(l));
				printElement(head(succ));

			}
			succ = tail(succ);
		}

		l = tail(l);
	}
}

void main(){
	FILE *f = fopen("magazzino.txt", "rt");
	if (f == NULL){
		return;
	}
	list l = emptylist();
	element e;
	while (fscanf(f, " %s %f", e.nome, &e.prezzo)!=EOF){
		l = cons(e, l);
	}
	float prezzo;
	printf("Inserisci prezzo:\n");
	scanf(" %f", &prezzo);
	visualizzaMaggiore(l, prezzo);

	trovaCoppie(l, 50.);
}