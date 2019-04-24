#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 20

int left(int i)
{
	return 2 * i;
}

int right(int i)
{
	return 2 * i + 1;
}

int Parent(int i) {
	return i / 2;
}

void scambia(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void MoveUp(int *A, int i, int heap_size){

	while (i != 1 && A[i] > A[Parent(i)]){
		scambia(&A[i], &A[Parent(i)]);
		i = Parent(i);
	}
}

void heapify(int *A, int i, int heap_size) {

	int l, r, largest;
	l = left(i);
	r = right(i);

	largest = i;

	if ((l <= heap_size) && (A[l] > A[i]))
		largest = l;

	if ((r <= heap_size) && (A[r] > A[largest]))
		largest = r;


	if (largest != i) {
		scambia(&A[i], &A[largest]);
		heapify(A, largest, heap_size);
	}
	return;
}


void build_heap(int *A, int heap_size) {
	int i;
	for (i = heap_size / 2; i >= 1; i--)
		heapify(A, i, heap_size);
	return;
}

void heapsort(int *A, int dim) {
	int i, heap_size;

	heap_size = dim;

	for (i = dim; i >= 2; i--) {
		scambia(&A[1], &A[i]);
		heapify(A, 1, --heap_size);
	}
	return;
}

int riempivettore(int *A)
{
	int i;
	for (i = 1; i < 15; i++)
		A[i] = MAX - i;

	return MAX - 1;
}

void stampavettore(int *A, int n)
{
	int i;
	printf("\n");
	for (i = 1; i <= n; i++)
		printf(" %d", A[i]);

	return;
}

int getElement(){
	int el;
	scanf("%d", &el);
	return el;
}

void main()
{
	int vettore[MAX];
	int n; /*numero di elementi*/
	int scelta;
	int el;
	char invio;

	n = riempivettore(vettore);

	build_heap(vettore, n);



	do {

		printf("\n\nMenu' Principale - CODA HEAP\n\nScegli l'operazione da eseguire: \n");
		printf("1. Inserisci elemento in coda\n");
		printf("2. Visualizza il prossimo elemento\n");
		printf("3. Servi il prossimo elemento\n");
		printf("0. Termina il programma\n");

		// acquisizione scelta utente
		scanf("%d", &scelta);
		scanf("%c", &invio);

		// interpretazione scelta ed esecuzione della relativa operazione

		switch (scelta) {

		case 0:
			printf("Uscita dal programma\n");
			break;

		case 1:
			printf("Inserire il numero dell'elemento: ");
			el = getElement();
			n++;
			vettore[n] = el;
			MoveUp(vettore, n, n);
			break;

		case 2:
			printf("\nIl prossimo elemento e': %d", vettore[1]);
			break;

		case 3:
			printf("\nIl prossimo elemento e': %d (eliminato)", vettore[1]);
			vettore[1] = vettore[n];
			n--;
			heapify(vettore, 1, n);

			break;

		default:
			printf("la scelta non e' corretta, inserirne un'altra\n");
		}
	} while (scelta != 0);


	heapsort(vettore, n);

	stampavettore(vettore, n);

	getchar();

	return;
}
