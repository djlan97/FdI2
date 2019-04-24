#define CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>

void getFromFile(const char *filename,list *l){		
	FILE *f = fopen(filename, "rt");
	if (f != NULL){
		int c;
		while (fscanf(f, " %d", &c)!=EOF){
			*l = cons(c,*l);
		}
	}
	fclose(f);	
}

void split(list *ll, list *lu, list l, element split){
	while (!empty(l)){
		element el = head(l);
		if (isLess(el, split)){
			*ll=cons(el, *ll);
		}
		else{
			*lu = cons(el, *lu);
		}
		l = tail(l);
	}
}

void main(void){
	list l=emptylist();
	getFromFile("prova.txt", &l);
	if (!empty(l)){
		showlist(l);
	}
	else{
		printf("lista vuota.");
	}

	printf("inserisci valore divisione lista:\t");
	element sp = getElement();
	list ll = emptylist(), lu = emptylist();
	split(&ll, &lu,l,sp);

	printf("elementi minori di %d:\t", sp);
	showlist(ll);
	printf("elementi maggiori (o uguali) di %d:\t", sp);
	showlist(lu);
}