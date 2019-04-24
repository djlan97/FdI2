#include "list.h"
#include <stdio.h>

void visualizzaMaggiore(double val, list l){
	while (!empty(l)){
		if (head(l).quantita == val){
			printElement(head(l));
		}
		l = tail(l);
	}
}

list insCoda(element e, list l){
	if (empty(l)){
		return cons(e, l);
	}
	list root = l;
	while (tail(l) != emptylist()){
		l = tail(l);
	}
	list t = (list)malloc(sizeof(item));
	t->value = copy(e);
	t->next = t;
	return root;
}

void stampaElemento(char *nome,list l){
	while (!empty(l)){
		if (strcmp(nome, head(l).prodotto)==0){
			printf("\n%d, %s\n", head(l).quantita, head(l).misura);
		}
		else l = tail(l);
	}
	printf("ELEMENTO NON PRESENTE");
}

void main(){
	int scelta;
	element e;
	list l = emptylist();
	do{
		printf("\nOperazioni disbonibili:\n1.inserisci\n2.inserisci in coda\n3.mostra elemento\n4.stampa elementi\n5.mostra quantità\n0.esci\ncosa faccio?");
		
		scanf(" %d", &scelta);
		switch (scelta)
		{
		case 0:
			break;
		case 1:
			e = getElement();
			if (member(e, l)){
				printf("ELEMENTO GIA' INSERITO0");
			}
			l = cons(e, l);
			break;
		case 2:
			e = getElement();
			if (member(e, l)){
				printf("ELEMENTO GIA' INSERITO0");
			}
			l = insCoda(e, l);
			break;
		case 3:
		{
				  char nome[20];
				  printf("Inserisci elemento:\t");
				  scanf(" %s", nome);
				  stampaElemento(nome, l);
				  break;
		}
		case 4:
			showlist(l);
			break;
		case 5:
			printf("Inserisci valore:\t");
			double val;
			scanf(" %f", &val);
			visualizzaMaggiore(val,l);
			break;
		default:
			scanf("Valore errato. Riprova!");
			break;
		}
	} while (scelta != 0);

}