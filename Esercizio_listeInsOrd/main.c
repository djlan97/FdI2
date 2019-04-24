#include "list.h"

list insOrd(element e, list l){
	list root = l,prec=l;
	if (empty(l)){
		l = cons(e, l);
		return l;
	}
	if (isLess(e, head(root))){
		root = cons(e, root);
		return root;
	}

	while (!empty(prec)){
		l = tail(l);
		if (empty(l)||isLess(e, head(l))){
			prec->next = cons(e, l);
			return root;
		}
		prec = tail(prec);
	}
	l = cons(e, l);
	return l;
}

void showMaggiore(list l){
	printf("\nInserisci valore:\t");
	float val = 0;
	list articoli = emptylist();
	scanf(" %f", &val);
	while (!empty(l)){
		if (head(l).prezzo > val){
			articoli = insOrd(head(l), articoli);
		}
		l = tail(l);
	}

	showlist(articoli);
}

void visualizzaEqual(list l, double val){
	list prec = l;
	while (!empty(prec)){
		l = tail(l);
		while (!empty(l)){
			if (val == head(prec).prezzo + head(l).prezzo){
				printf("\n");
				printElement(head(prec));
				printf("\t");
				printElement(head(l));
				printf("\n");
			}
			l = tail(l);
		}
		prec = tail(prec);
		l = prec;
	}
}

void main(){
	FILE *f = fopen("magazzino.txt", "rt");
	if (f == NULL){
		fclose(f);
		return;
	}
	element e;
	list l = NULL;
	while (fscanf(f, " %s %f", e.nome, &e.prezzo)>0){
		l = cons(e, l);
	}
	showMaggiore(l);
	visualizzaEqual(l, 50.);

}