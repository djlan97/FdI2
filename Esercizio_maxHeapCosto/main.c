#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
	char nome[20];
	float costo;
}Processo;

typedef Processo element;

int isEqual(element e1, element e2){
	return (e1.costo == e2.costo);
}

int isLess(element e1, element e2){
	return (e1.costo < e2.costo);
}

int parent(int i){
	return i / 2;
}

int left(int i){
	return 2 * i;
}

int right(int i){
	return 2 * i + 1;
}

void printElement(element e){
	printf("%s\t%f", e.nome, e.costo);
}

void scambia(element *e1, element *e2){
	element tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

void moveUp(element *h, int i, int heap_size){
	if (i == 1){
		return;
	}
	while (i != 1 && isLess(h[parent(i)],h[i])){
		scambia(&h[parent(i)], &h[i]);
		i = parent(i);
	}
}

void moveDown(element *h, int i, int heap_size){
	int l, r, largest = i;
	int done;
	do{
		l = left(i);
		r = right(i);
		done = 1;

		if (l <= heap_size && isLess(h[largest],h[l])){
			largest = l;
		}
		if (r <= heap_size && isLess(h[largest], h[r])){
			largest = r;
		}
		if (largest != i){
			done = 0;
			scambia(&h[i], &h[largest]);
			i = largest;
		}

	} while (!done);
}

void pop(element *h, int *heap_size, element *popped){
	*popped = h[1];
	scambia(&h[1], &h[*heap_size]);
	--(*heap_size);
	moveDown(h, 1, *heap_size);
	h = realloc(h, ((*heap_size) + 1)*sizeof(element));
}

void main(){
	FILE *f = fopen("processi.dat", "rt");
	if (f == NULL){
		fclose(f);
		return;
	}
	element *h = (element*)malloc(sizeof(element));
	int heap_size = 0;
	element e;	
	while (fscanf(f, " %s %f", e.nome, &(e.costo)) > 0){
		++heap_size;
		h[1];
		h[2];
		h = (element*)realloc(h,(heap_size+1)*sizeof(element));
		h[heap_size] = e;
		moveUp(h, heap_size, heap_size);
	}
	element popped;
	pop(h, &heap_size, &popped);
	printElement(popped);
}