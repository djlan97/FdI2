#if !defined ORDINAMENTO_H
#define ORDINAMENTO_H

#include <stdbool.h>

extern void naiveSort(int v[], int dim);
extern void bubbleSort(int v[], int dim);
extern void insertSort(int v[], int dim);
extern void insMinore(int v[], int lastpos);
extern void quickSort(int v[], int first, int last);
extern void mergeSort(int v[], int first, int last);
extern void merge(int v[], int i1, int i2, int last);

/*FUNZIONI DI SUPPORTO*/
extern void scambia(int *v1, int *v2);
extern int trovaPosMax(int v[], int n);

#endif/*ORDINAMENTO_H*/