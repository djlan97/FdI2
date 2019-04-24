#include "heapvect.h"

int parent(int i){ return i / 2; }

int left(int i){ return 2 * i; }

int right(int i){ return 2 * i + 1; }

void heapify(element *A, int i, int heap_size){
	int l, r, largest = i;
	l = left(i);
	r = right(i);
	if ((l <= heap_size) && (A[l] > A[i])) largest = l;
	if ((r <= heap_size) && (A[r] > A[largest])) largest = r;
	if (largest != i){
		scambia(&A[i], &A[largest]);
		heapify(A, largest, heap_size);
	}
	return;
}

void build_heap(element *A, int heap_size){
	int i;
	for (i = heap_size / 2; i >= 1; i--){
		heapify(A, i, heap_size);
	}
	return;
}

void heapsort(element *A, int dim){
	int i, heap_size = dim;
	for (i = dim; i >= 2; i--){
		scambia(&A[1], &A[i]);
		heapify(A, 1, --heap_size);
	}
}

void moveUp(element *A, int i, int heap_size){
	while (i != 1 && A[i] > A[parent(i)]){
		scambia(&A[i], &A[parent(i)]);
		i = parent(i);
	}
}

void stampavettore(element *A, int n)
{
	int i;
	printf("\n");
	for (i = 1; i <= n; i++)
		printf(" %d", A[i]);

	return;
}

int riempivettore(element *A)
{
	int i;
	for (i = 1; i < MAX; i++)
		A[i] = MAX - i;

	return MAX - 1;
}

/*FUNZIONI DI SUPPORTO*/
void scambia(element *a, element*b){
	element tmp = *a;
	*a = *b;
	*b = tmp;
}