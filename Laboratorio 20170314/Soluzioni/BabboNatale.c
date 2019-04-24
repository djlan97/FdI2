// ESERCIZIO SLITTA DI BABBO NATALE
// Ogni anno che passa Babbo Natale fatica sempre più a caricare la slitta dei regali.
// Fortunatamente per lui gli studenti decidono di aiutarlo scrivendo una procedura 
// ricorsiva:

//void RiempiSlitta(int n, int s, int v[], int peso[], int best[], int *max, int count, int sommaparziale, int capienza);

// dove:
// n: è il numero di regali totali disponibili
// s: è la posizione corrente (a che livello dell'albero di backtrack si trova la funzione corrente)
// v: è il vettore binario (0-1) dei pacchi caricati (1) e non (0) dalla soluzione corrente.
// peso: è il vettore dei pesi relativi ai vari pacchi
// best: è il vettore binario (0-1) della miglior combinazione di pacchi trovata
// max: è il numero di regali caricati dalla soluzione migliore (best)
// count: è il numero di pacchi caricato dalla soluzione corrente
// sommaparziale: è la somma dei pesi dei pacchi caricati nella soluzione corrente
// capienza: è la portata massima della slitta

//E' necessario massimizzarne il numero dei regali caricati senza superare il massimo peso consentito (capienza).

// **NOTA**: essendo v e best due vettori che possono contenere solo i valori 0 e 1 era più opportuno utilizzare un tipo di
// dato diverso dell'int. Ad esempio si poteva utilizzare il tipo char o bool!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RiempiSlitta(const int n, int s, int v[], const int peso[], int best[], int *max, int count, int sommaparziale, const int capienza){

	// Se sono una foglia dell'albero di backtrack la slitta è piena.
	if (s == n) {
		// Mostro la soluzione corrente
		printf("Peso: %4d, Regali: %2d, Combinazione: ", sommaparziale, count);
		for (int i = 0; i<n; ++i){
			printf("%d ", v[i]);
		}
		printf("\n");
		
		// Se la soluzione corrente è migliore della best aggiorno la best
		if (count>*max){
			*max = count;
			memcpy(best, v, n*sizeof(int));
			// In alternativa si poteva usare un for
			//for (int i = 0; i < n; i++) {
			//	best[i] = v[i];
			//}
		}
		return;
	}

	// Scendo l'albero considerando il caso in cui non carico il pacco corrente
	v[s] = 0;
	RiempiSlitta(n, s + 1, v, peso, best, max, count, sommaparziale, capienza);

	// Se posso, scendo l'albero considerando il caso in cui caricao il pacco corrente
	if (sommaparziale + peso[s] <= capienza){
		v[s] = 1;
		RiempiSlitta(n, s + 1, v, peso, best, max, count + 1, sommaparziale + peso[s], capienza);
	}
}

// Provare a scrivere una soluzione alternativa in cui sommaparziale NON viene passato come parametro (più costosa della precedente).
void RiempiSlittaAlternativa(const int n, int s, int v[], const int peso[], int best[], int *max, int count, const int capienza){

	// Prima di tutto calcolo la sommaparziale corrente
	int sommaparziale = 0; 
	for (int i = 0; i < s; ++i){
		if (v[i] == 1){
			sommaparziale += peso[i];
		}
	}

	// Se sono una foglia dell'albero di backtrack la slitta è piena.
	if (s == n) {
		// Mostro la soluzione corrente
		printf("Peso: %4d, Regali: %2d, Combinazione: ", sommaparziale, count);
		for (int i = 0; i<n; ++i){
			printf("%d ", v[i]);
		}
		printf("\n");

		// Se la soluzione corrente è migliore della best aggiorno la best
		if (count>*max){
			*max = count;
			memcpy(best, v, n*sizeof(int));
			// In alternativa si poteva usare un for
			//for (int i = 0; i < n; i++) {
			//	best[i] = v[i];
			//}
		}
		return;
	}

	// Scendo l'albero considerando il caso in cui non carico il pacco corrente
	v[s] = 0;
	RiempiSlittaAlternativa(n, s + 1, v, peso, best, max, count, capienza);

	// Se posso, scendo l'albero considerando il caso in cui caricao il pacco corrente
	if (sommaparziale + peso[s] <= capienza){
		v[s] = 1;
		RiempiSlittaAlternativa(n, s + 1, v, peso, best, max, count + 1, capienza);
	}
}

void main(void){
		
	int peso[] = { 10, 20, 30, 15, 5, 25, 35, 80, 9, 3 }; // Per cambiare la lista dei pacchi basta aggiornare questo vettore

	int numRegali = sizeof(peso) / sizeof(int);

	int *v;
	int *best;	
	
	best = calloc(numRegali, sizeof(int));
	v = malloc(numRegali*sizeof(int));

	int max = 0;
	int capienza = 80;

	//RiempiSlitta(numRegali, 0, v, peso, best, &max, 0, 0, capienza);
	RiempiSlittaAlternativa(numRegali, 0, v, peso, best, &max, 0, capienza);

	printf("Il numero massimo di regali che Babbo Natale puo' caricare e' %d.\nPer farlo puo' utilizzare la seguente combinazione di pacchi (non e' detto che sia l'unica):\n", max);
	for (int i = 0; i < numRegali; ++i){
		printf("%d ", best[i]);
	}
	printf("\n");
}