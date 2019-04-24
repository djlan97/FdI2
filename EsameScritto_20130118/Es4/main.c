#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "list.h"
#include <stdio.h>
void visualizzaCoppie(list l){
	if (empty(l)){
		return;
	}
	list v = emptylist();
	list succ = emptylist();
	while (!empty(l)){
		v = cons(head(l), v);
		succ = tail(l);
		while (!empty(succ)){
			if (head(l).interessi == head(succ).interessi){
				v = cons(head(succ), v);
				showlist(v);
			}
			succ = tail(succ);
		}
		v = emptylist();
		l = tail(l);
	}
}
list insCoda(element e, list l){
	if (empty(l)){
		return cons(e, l);
	}
	list rootl=l;
	while (!empty(tail(l))){
		l = tail(l);
	}
	list t = (list)malloc(sizeof(item));
	t->value = copy(e);
	t->next = emptylist();
	l->next = t;
	return rootl;
}
void trovaMax(list l){
	if (empty(l)){
		printf("Lista vuota!");
		return;
	}
	element lmax = head(l);
	l = tail(l);
	int max = 0;
	while (!empty(l)){
		if (head(l).interessi > lmax.interessi){
			lmax = head(l);
		}
		l = tail(l);
	}
	printElement(lmax);
}

void main(){
	list l = emptylist();
	element e;
	FILE *f = fopen("utenti.txt", "rt");
	if (f == NULL){
		return;
	}
	char tmp;
	while (fscanf(f, " %[^:]:", e.nome)!=EOF){
		int count = 0;
		while (fscanf(f, " %*[^,\n]") !=EOF){
			tmp = getc(f);
			count++;
			if (tmp == '\n'||tmp==EOF){
				break;
			}
		}
		e.interessi = count;
		l = insCoda(e, l);
	}

	trovaMax(l);
	visualizzaCoppie(l);
	fclose(f);
}