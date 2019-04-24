#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef bool boolean;

typedef char* element;

typedef struct list_int{
	element tipo;
	struct list_int *nexti;
}interesse;

typedef struct list_element{
	element nome;
	struct list_element *nextp;
	interesse *interessi;
}persona;

typedef persona* listp;
typedef interesse* listi;

//FUNZ ELEMENT

bool isEqual(element e1, element e2){
	return (strcmp(e1, e1) == 0);
}

bool isLess(element e1, element e2){
	return (strcmp(e1, e1) < 0);
}

element getElement(){
	element el;
	scanf(" %s", &el);
	return el;
}

void printElement(element el){
	printf(" %s", el);
}

//PRIMITIVE

listp conslp(element e, listp l){
	listp t;
	t = (listp)malloc(sizeof(persona));
	t->nome = copy(e);
	t->nextp = l;
	t->interessi = NULL;
	return t;
}

listi consli(element e, listi l){
	listi t;
	t = (listi)malloc(sizeof(interesse));
	t->tipo = copy(e);
	t->nexti = l;
	return t;
}









void main(){
	FILE *f = fopen("utenti.txt", "rt");
	if (f == NULL){
		fclose(f);
		return;
	}

	
	listp l = NULL;

	while (1){
		char tmp[30];
		if (!fscanf(f, " %[^:]", tmp)){
			break;
		}		
		l = conslp(tmp, l);
		fgetc(f);
		while (fscanf(f, " %[^,\n]", tmp)){
			l->interessi = consli(tmp,l->interessi);
			fgetc(f);
		}
	}
}