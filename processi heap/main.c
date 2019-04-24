#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
	char Nome[20];
	float Costo;
} Processo;

typedef Processo element;

// Confronta due element a e b e restituisce 0 se sono uguali ('a' e 'b' hanno lo stesso codice di accesso), 1 se a > b ('a' ha codice di accesso con priorit� maggiore rispetto a 'b') e -1 se a < b ('a' ha codice di accesso con priorit� minore rispetto a 'b')
int elecmp(const element *a, const element *b) {
	
	if (a->Costo > b->Costo) {
		return 1;
	}
	else {
		return -1;
	}
}

// Scambia i valori degli element specificati
void swap(element *a, element *b) {
	element temp = *a;
	*a = *b;
	*b = temp;
	return;
}

/** @brief Restituisce l'indice del padre del nodo 'i'

@param[in] 'i' - indice di un nodo

@return indice del padre del nodo 'i'
*/
static unsigned parent(unsigned i){
	return i / 2;
}

/** @brief Restituisce l'indice del figlio sinistro del nodo 'i'

@param[in] 'i' - indice di un nodo

@return indice del figlio sinistro del nodo 'i'
*/
static unsigned left(unsigned i) {
	return 2 * i;
}

/** @brief Restituisce l'indice del figlio destro del nodo 'i'

@param[in] 'i' - indice di un nodo

@return indice del figlio destro del nodo 'i'
*/
static unsigned right(unsigned i) {
	return 2 * i + 1;
}

// MoveUp iterativa per una max heap 
void MoveUp_MaxHeap(element *H, unsigned i, size_t heap_size) {
	while (i != 1 && elecmp(&H[i], &H[parent(i)]) > 0) {
		swap(&H[i], &H[parent(i)]);
		i = parent(i);
	}
}

// MoveUp ricorsiva per una max heap
void MoveUp_MaxHeap_Recursive(element *H, unsigned i, size_t heap_size) {
	if (i == 1) {
		return; // I'm the root!
	}

	if (elecmp(&H[i], &H[parent(i)]) > 0) {
		swap(&H[i], &H[parent(i)]);
		MoveUp_MaxHeap_Recursive(H, parent(i), heap_size);
	}

	return;
}

// MoveDown iterativa per una max heap 
void MoveDown_MaxHeap(element *H, unsigned i, size_t heap_size) {

	unsigned l, r, largest = i;
	bool done;
	do {
		done = true;
		l = left(i);
		r = right(i);

		if ((l <= heap_size) && elecmp(&H[l], &H[largest]) > 0) {
			largest = l;
		}

		if ((r <= heap_size) && elecmp(&H[r], &H[largest]) > 0){
			largest = r;
		}

		if (largest != i) {
			swap(&H[i], &H[largest]);
			i = largest;
			done = false;
		}

	} while (!done);

	return;
}

// MoveDown ricorsiva per una max heap 
void MoveDown_MaxHeap_Recursive(element *H, unsigned i, size_t heap_size) {
	if (i > heap_size) {
		abort();
	}

	unsigned l, r, largest = i;
	l = left(i);
	r = right(i);

	if ((l <= heap_size) && elecmp(&H[l], &H[largest]) == 1)
		largest = l;

	if ((r <= heap_size) && elecmp(&H[r], &H[largest]) == 1)
		largest = r;

	if (largest != i) {
		swap(&H[i], &H[largest]);
		MoveDown_MaxHeap_Recursive(H, largest, heap_size);
	}

	return;
}

// Trasforma un vettore qualsiasi H in una coda MaxHeap utilizando un metodo iterativo
void Heapify_MaxHeap(element *H, size_t heap_size) {
	for (int i = heap_size / 2; i >= 1; i--) {
		MoveDown_MaxHeap(H, i, heap_size);
	}

	return;
}

// Funzione ausiliaria per la funzione heapify ricorsiva
void Heapify_MaxHeap_Recursive_Auxiliary(element *H, unsigned i, size_t heap_size) {
	if (left(i) > heap_size && right(i) > heap_size) {
		// Sono una foglia quindi termino
		return;
	}

	Heapify_MaxHeap_Recursive_Auxiliary(H, left(i), heap_size);
	Heapify_MaxHeap_Recursive_Auxiliary(H, right(i), heap_size);
	MoveDown_MaxHeap_Recursive(H, i, heap_size);
}

// Trasforma un vettore qualsiasi H in una coda MaxHeap utilizando un funzione ricorsiva ausiliaria (Heapify_MaxHeap_Recursive_Auxiliary)
void Heapify_MaxHeap_Recursive(element *H, size_t heap_size) {
	if (heap_size > 1) {
		// Inizia la ricorsione a partire dalla root della coda heap
		Heapify_MaxHeap_Recursive_Auxiliary(H, 1, heap_size);
	}
	return;
}

// Aggiunge un nuovo elemeneto ad una coda MaxHeap e ripristina la priorit� eseguento la MoveUp. La funzione restituisce poi il puntatore alla nuova MaxHeap
element *Push_MaxHeap(const element *new_e, element *H, size_t *heap_size) {
	(*heap_size)++;
	H = realloc(H, (*heap_size + 1)*sizeof(element));
	H[*heap_size] = *new_e;
	MoveUp_MaxHeap(H, *heap_size, *heap_size);

	return H;
}

// Estrae l'elemento massimo da una coda MaxHeap (salvandolo in popped), lo scambia con l'ultimo valore della code e ripristina la priorit� eseguento la MoveDown. La funzione restituisce poi il puntatore alla nuova coda MaxHeap
element *Pop_MaxHeap(element *H, size_t *heap_size, element *popped) {

	*popped = H[1];
	swap(&H[1], &H[*heap_size]);

	(*heap_size)--;
	MoveDown_MaxHeap_Recursive(H, 1, *heap_size);

	return realloc(H, (*heap_size + 1)*sizeof(element));
}

// Crea una Heap vuota (la prima posizione non viene utilizzata)
element *CreateHeap() {
	element *H = malloc(1 * sizeof(element));
	return H;
}

// Elimina il valore massimo da una MaxHeap senza dire qual � e restituisce il puntatore alla nuova coda MaxHeap
element *DeleteMax_MaxHeap(element *H, size_t *heap_size) {
	swap(&H[1], &H[*heap_size]);
	(*heap_size)--;
	MoveDown_MaxHeap_Recursive(H, 1, *heap_size);
	return realloc(H, (*heap_size + 1)*sizeof(element));
}

// Restituisce il valore massimo di una MaxHeap senza eliminarlo dalla coda 
element FindMax_MaxHeap(element *H, size_t heap_size) {
	if (heap_size < 1) {
		abort();
	}

	return H[1];
}

// Elimina un nodo arbitrario (specificato) da una coda MaxHeap restituisce il puntatore alla nuova coda MaxHeap
element *Delete_MaxHeap(element *to_delete, element *H, size_t *heap_size) {
	for (unsigned i = 1; i <= *heap_size; ++i) {
		if (elecmp(&H[i], to_delete) == 0) {
			swap(&H[i], &H[*heap_size]);
			MoveDown_MaxHeap(H, i, --(*heap_size));
			return realloc(H, (*heap_size + 1)*sizeof(element));
		}
	}

	return H;
}

void DeleteHeap(element *H) {
	free(H);
}

// Algoritmo di ordinamo basato su coda heap
void Heapsort_MaxHeap(element *H, size_t heap_size) {
	int dim = heap_size;
	for (int i = heap_size; i >= 2; i--) {
		swap(&H[1], &H[i]);
		MoveDown_MaxHeap(H, 1, --dim);
	}
}

void ShowElement(element el) {
	printf("Nome:\t%s\nCosto:\t%f\n", el.Nome, el.Costo);
}


void main(){
	element *H = CreateHeap();
	size_t heapsize = 0;
	FILE *f = fopen("processi.dat", "rb");
	if (f == NULL){
		return;
	}
	
	element e;
	while (fscanf(f, " %s %f", e.Nome, &e.Costo) != EOF){
		H=Push_MaxHeap(&e,H,&heapsize);
	}
	e=FindMax_MaxHeap(H, heapsize);

	H=Pop_MaxHeap(H, &heapsize, &e);

}