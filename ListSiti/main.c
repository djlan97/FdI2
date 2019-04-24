#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>
#include <string.h>
int cercaStr(char *to_f, char *rsc){
	for (size_t i = 0; i < strlen(to_f); i++){
		if (to_f[i] != rsc[i]||rsc[i]==0){
			return 0;
		}
	}
	return 1;
}
list insOrd(element e, list l){
	if (empty(l)){
		return cons(e, l);
	}
	if (e.accessi > head(l).accessi){
		return cons(e,l);
	}
	l->next = insOrd(e, tail(l));
	return l;
}

void main(){
	FILE *f = fopen("internet.txt", "rt");
	if (f == NULL){
		return;
	}
	element e;
	list l = NULL;
	while (fscanf(f, " %s %d", e.dominio, &e.accessi) != EOF){
		l = insOrd(e, l);
	}
	printf("I migliori tre siti secondo il numero di accessi sono:\n");
	list t = l;
	for (int i = 0; i < 3;){
		if (t != NULL){
			printf("%d)\t", ++i);
			printElement(head(t));
		}
		t = tail(t);
	}
	char str[20];
	printf("Inserisci stringa:\n");
	scanf(" %s",str);
	t = l;
	while (!empty(t)){
		if (cercaStr(str, head(t).dominio)){
			printElement(head(t));
		}
		t = tail(t);
	}
}