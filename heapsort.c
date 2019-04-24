#include <stdio.h>
#define MAX 50

int left(int i)
{
 return 2*i;
}

int right(int i)
{
 return 2*i+1;
}


void scambia(int *n1,int *n2)
{
 int temp;

 temp = *n1;
 *n1 = *n2;
 *n2 = temp;
}

void heapify( int *A, int i, int heap_size ) {

int l, r, largest;
l = left(i);
r = right(i);

largest = i;

if (( l <= heap_size ) && ( A[l] > A[i] ))
	largest = l;

if (( r <= heap_size ) && ( A[r] > A[largest] ))
	largest = r;


if ( largest != i ) {
	scambia( &A[i], &A[largest] );
	heapify( A, largest, heap_size );
}
return;
}


void build_heap( int *A, int heap_size ) {
int i;
for( i = heap_size/2; i >= 1; i-- )
	heapify( A, i, heap_size );
return;
}

void heapsort( int *A, int dim ) {
int i, heap_size ;

   heap_size = dim;

for ( i = dim; i >= 2; i-- ) {
	scambia( &A[1], &A[i] );
	heapify( A, 1, --heap_size );
}
return;}

int riempivettore(int *A)
{
int i;
for( i = 1; i < MAX; i++ )
	A[i] = MAX - i;

 return MAX-1;
}

void stampavettore(int *A)
{
int i;
printf("\n");
for( i = 1; i < MAX; i++ )
	printf(" %d", A[i]);

 return;
}

void main()
{
 int vettore[MAX];
 int n; /*numero di elementi*/

 n=riempivettore(vettore);

 build_heap(vettore,n);

 heapsort(vettore,n);

 stampavettore(vettore);

	getchar();

 return;
}
