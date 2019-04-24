// ESERCIZIO OMBRELLONI

// Giovanni, Mario e Luca decidono di andare a trascorrere una giornata al mare.
// Giunti al mare decidono di affittare ciascuno un ombrellone: tutti e tre 
// vogliono affittare un ombrellone in prima fila, senza però essere vicini tra loro.

// La prima fila, contenente n (=10) ombrelloni ed è tutta libera: aiutate il bagnino, 
// scrivendo una procedura ricorsiva, a trovare le possibili posizioni dei tre ragazzi.

// Mostrare in output quante e quali sono le soluzioni. Si consiglia di utilizzare la 
// seguente procedura ricorsiva:

//void SubsetK(int n, int s, int v[], int *num, int count, int k)

//dove
// n: è il numero n degli ombrelloni in prima fila (qui fisso a 10)
// s: è la posizione corrente (a che livello dell'albero di backtrack si trova la funzione corrente)
// v: è il vettore binario (0-1) del posizionamento corrente 1 = posizionato, 0 = NON posizonato
// num: è il numero delle soluzioni trovate
// count: è il contatore dei ragazzi posizionati fino ad ora nella soluzione corrente
// k: (< n) è il numero dei ragazzi da posizionare (qui fisso a 3)

// **NOTA**: essendo v un vettore che può contenere solo i valori 0 e 1 era più opportuno utilizzare un tipo di
// dato diverso dall'int. Ad esempio si poteva utilizzare il tipo char o bool!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SubsetK(const int n, int s, int v[], int *num, int count, const int k){

	// Controllo se la soluzione è completa (ho già posizionato k ragazzi)
	if (count == k) {
		printf("%4d) ", *num + 1);
		(*num)++;
		// Completo il vettore della soluzione corrente
		memset(v + s, 0, (n-s)*sizeof(int));
		// In alternativa al memmset si poteva utilizzare un ciclo
		//for (int i = s; i < n; i++) {
		//	v[i] = 0;
		//}

		// Stampo su stdout la soluzione corrente
		for (int i = 0; i < n; i++){
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}

	// Sono giunto al termine del vettore e la soluzione non è accettabile (non ho posizionato tutti i ragazzi)
	if (s == n) return;

	// Proseguo il backtrack senza posizionare alcun ragazzo
	v[s] = 0;
	SubsetK(n, s + 1, v, num, count, k);

	// Se posso, proseguo il backtrack posizionando un ragazzo
	if (s == 0 || (s > 0 && v[s - 1] == 0)){
		v[s] = 1;
		SubsetK(n, s + 1, v, num, count + 1, k);
	}

}

void main(void){
	
	int n = 10; 
	int k = 3; 

	int slzTrovate = 0;
	int *v;

	v = malloc(n*sizeof(int));

	SubsetK(n, 0, v, &slzTrovate, 0, k);
	printf("Il numero di soluzioni trovate e' pari a %d\n", slzTrovate);
}