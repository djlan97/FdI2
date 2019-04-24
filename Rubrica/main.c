#define _CRT_SECURE_NOWARNINGS
#include "list.h"
#include <stdio.h>
#include <string.h>

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

list eliminaIndirizzo(element e, list l){
	if (empty(l)) return emptylist();
	if (isEqual(e, head(l))){
		return tail(l);
	}
	else{
		return cons(head(l), eliminaIndirizzo(e,tail(l)));
	}
}

void trovaIndirizzo(element e, list l){
	if (empty(l)){
		printf("LISTA VUOTA!\n");
		return;
	}
	while (!empty(l)){
		
		if (isEqual(e, head(l))){
			printf("Indirizzo:\t%s\n", head(l).via);
			return;
		}
		l = tail(l);
	}
	printf("ELEMENTO NON PRESENTE!\n");

}

list insCoda(element e, list l){
	list root = l;
	if (empty(l)){
		l=cons(e, l);
		return l;
	}
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
	printf("CIAO! IO SONO LA TUA RUBRICA!\n");
	element e;
	list l = emptylist();
	int cod;
	do{
		printf("\nCodici disponibili:\n1=Inserisci un nuovo indirizzo in coda\n2=Stampa tutti gli indirizzi\n3=Cerca un indirizzo\n4=Elimina un indirizzo\n5=Ordina indirizzi\n0=Esci\nCosa devo fare?\n");
		scanf(" %d", &cod);
		switch (cod){
		case 1:{
				   printf("\n***INSERIMENTO IN CODA***\n");
				   e = getElement();
				   l = insCoda(e, l);
				   showlist(l);
				   break;
		}
		case 2:{
				   showlist(l);
				   break;
		}
		case 3:{
				   printf("***CERCA INDIRIZZO***\n");
				   printf("Nominativo:\t");
				   scanf(" %[^\n]", &e.nome);
				   printf("\n");
				   trovaIndirizzo(e, l);
				   break;
		}
		case 4:{
				   printf("***ELIMIA INDIRIZZO***\n");
				   printf("Nominativo:\t");
				   scanf(" %[^\n]", &e.nome);
				   printf("\n");
				   l = eliminaIndirizzo(e, l);
				   showlist(l);
				   break;
		}
		case 5:{
				   printf("***ORDINA RUBRICA***\n");
				   l = ordinaLista(l);
				   showlist(l);
				   break;
		}
		case 0:{
				   break;
		}
		default:{
					printf("VALORE NON VALIDO, RIPROVARE!\n");
					break;
		}
		}
	} while (cod != 0);
}