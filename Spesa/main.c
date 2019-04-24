#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>

void trovaMaggiori(float q, list l){
	if (empty(l)){
		printf("LISTA VUOTA!\n");
		return;
	}
	printf("Articoli con quantità maggiore di %f\n", q);
	while (!empty(l)){
		if (head(l).quantita > q){
			printElement(head(l));
		}
		
		l = tail(l);
	}
}

void trovaArticolo(element e, list l){
	if (empty(l)){
		printf("LISTA VUOTA!\n");
		return;
	}
	while (!empty(l)){
		if (isEqual(e, head(l))){
			printf("Quantità:\t");
			scanf(" %f", &e.quantita);
			printf("\n");
			printf("Unità di misura:\t");
			scanf(" %[^\n]", e.misura);
			printf("\n");
			return;
		}
		l = tail(l);
	}
	printf("ARTICOLO NON PRESENTE!\n");
}

list insCoda(element e, list l){
	if (empty(l)){
		return cons(e, l);
	}
	list root = l;
	while (!empty(tail(l))){
		l = tail(l);
	}

	list t = (list)malloc(sizeof(item));
	t->value = copy(e);
	t->next = emptylist();
	l->next = t;
	return root;
}

void main(){
	list l = emptylist();
	element e;
	int c;
	do{
		printf("Operazioni disponibili:\n1=Inserisci elemento da acquistare\n2=Inserisci elemento da acquistare in coda\n3=Trova quantità e misura dato un nome\n4=Stampa lista della spesa\n5=Stampa elementi maggiori di una quantità data\n0=Esci\nCosa devo fare?\n");
		scanf(" %d", &c);
		switch (c)
		{
		case 1:{
				   printf("***INSERIMENTO***\n");
				   e = getElement();
				   if (member(e, l)){
					   printf("ELEMENTO GIA' PRESENTE!\n");
				   }
				   else{
					   l = cons(e, l);
					   showlist(l);
				   }
				   break;
		}
		case 2:{
				   printf("***INSERIMENTO***\n");
				   e = getElement();
				   l = insCoda(e, l);
				   if (member(e, l)){
					   printf("ELEMENTO GIA' PRESENTE!\n");
				   }
				   else{
					   l = insCoda(e, l);
					   showlist(l);
				   }
				   break;
		}
		case 3:{
				   printf("***CERCA QUANTITA' E UNITA' DI MISURA***\n");
				   printf("Articolo:\t");
				   scanf(" %[^\n]", e.nome);
				   printf("\n");
				   trovaArticolo(e, l);
				   break;
		}
		case 4:{
				   printf("***ARTICOLI DA ACQUISTARE***\n");
				   showlist(l);
				   break;
		}
		case 5:{
				   printf("***CERCA ELEMENTI CON QUANTITA' MAGGIORE DI...***\n");
				   printf("Quantità:\t");
				   float q;
				   scanf(" %f", &q);
				   printf("\n");
				   trovaMaggiori(q, l);
				   break;
		}
		case 0:{
				   break;
		}
		default:
			printf("VALORE NON VALIDO, RIPROVARE!");
			break;
		}
	} while (c != 0);
}