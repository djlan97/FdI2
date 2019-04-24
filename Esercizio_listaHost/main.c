#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "list.h"

list consOrd(element e, list l){
	if (empty(l)){
		l = cons(e, l);
		return l;
	}
	if (isLess(e, head(l))){
		l->next = consOrd(e, tail(l));
		return l;
	}
	if (!isLess(e, head(l)))
		l = cons(e, l);
		return l;
}


void bestn(int n, list l){
	printf("\nI %d siti più popolari sono:\n",n);
	printf("HOST\tNUMERO ACCESSI\n");
	for (int i = 0; i < n; i++){
		printElement(head(l));
		l = tail(l);
	}
}

void findString(char *s,list l){
	printf("\nLa stringa %s è all'interno dei seguenti domini:\n", s);
	while (!empty(l)){
		if (strncmp(s, head(l).host, strlen(s))==0){
			printElement(head(l));
		}
		l = tail(l);
	}
}

void main(){
	FILE *f = fopen("internet.txt", "rt");
	if (f == NULL){
		return;
	}
	list l = emptylist();
	element el;
	while (fscanf(f, " %s %d", &el.host, &el.accessi)!=EOF){
		l = consOrd(el, l);
	}
	fclose(f);
	bestn(3, l);
	printf("\nInserisci stringa da cercare: \t");
	char tmp[MAX];
	scanf(" %s", tmp);

	findString(tmp,l);
}