#if !defined HEAPVECT_H
#define HEAPVECT_H
#define MAX 20
#include "element.h"

extern int parent(int i);
extern int left(int i);
extern int right(int i);
extern void heapify(element *A, int i, int heap_size);
extern void build_heap(element *A, int heap_size);
extern void heapsort(element *A, int dim);
extern void moveUp(element *A, int i, int heap_size);
extern void stampavettore(element *A, int n);
extern int riempivettore(element *A);

/*FUNZIONI DI SUPPORTO*/
extern void scambia(int *a, int*b);
#endif /*HEAPVECT_H*/