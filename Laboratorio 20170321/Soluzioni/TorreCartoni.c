// ESERCIZIO TORRE DI CARTONI

// All’interno di un magazzino ci sono n pacchi. Ogni pacco è caratterizzato da un peso, un' altezza, e da un limite
// massimo di peso che il pacco può sostenere sopra di se'. Pesi, altezze e limiti sono interi positivi.

// Per rappresentare queste caratteristiche si utilizzi la struttura :

//typedef struct {
//	unsigned peso;
//	unsigned altezza;
//	unsigned limite;
//} pacco;

// Scrivere una funzione:

//void CostruisciTorre(int n, pacco *pacchi, int s, torre *corrente, torre *best, int *listaUso);

// che, dato un array di n pacchi, calcoli qual è l’altezza massima di una pila di pacchi che può essere formata con
// essi rispettando il vincolo che nessun pacco abbia sopra di se' un peso superiore al limite consentito. I parametri 
// della funzione CostruisciTorre sono elencati di seguito: 

// n: numero di pacchi nell'array,
// pacchi: array di pacchi disponibili,
// s: posizione corrente (a che livello dell'albero di backtrack si trova la funzione corrente),
// corrente: torre corrente,
// best: miglior torre,
// listaUso: vettore binario (0-1) che tiene traccia dei pacchi utilizzati (=1) e non (=0) del vettore dei pacchi.

// Il tipo "torre" è definito come segue: 

//typedef struct {
//	unsigned altezza;
//	int *pacchiTorre;
//} torre;

// dove altezza rappresenta l'altezza della torre e pacchiTorre è un puntatore ad un array che contiene la lista dei pacchi
// utilizzati per costruire la torre (lista delle posizioni). Ad esempio, se nell'array dei pacchiTorre di una torre troviamo
// i valori 0, 2, 1 significa che la torre è costruita con i pacchi in posizione 0, 2 e 1 dell'array di pacchi. Suggerimento:  
// si utilizzi il valore -1 per modellare il caso "nessun pacco".

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	unsigned peso;    // Peso del pacco	
	unsigned altezza; // Altezza del pacco	
	unsigned limite;  // Limite di peso che il pacco può sorregere
} pacco;

typedef struct {
	unsigned altezza;  // Altezza torre
	int *pacchiTorre;  // Vettore che tiene traccia dei pacchi utilizzati e dell'ordine con cui sono stai caricati
} torre;


// La funzione "verifica" controlla se è possibile o meno caricare un pacco sulla torre.
// corrente: torre corrente, 
// f: dimensione della torre corrente, 
// pacchi: array dei pacchi disponibili, 
// i: posizione del pacco che si vuole inserire (verificare) alla base della torre corrente
bool verifica(torre *corrente, int f, pacco *pacchi, int i)
{
	unsigned pesoTotale = 0;

	for (int j = 0; j<f; j++){
		pesoTotale += pacchi[corrente->pacchiTorre[j]].peso;
	}

	if (pacchi[i].limite < pesoTotale){
		return false; // NON è possibili caricare il pacco
	}

	return true; // E' possibile caricare il pacco
}

void CostruisciTorre(int n, pacco *pacchi, int s, torre *corrente, torre *best, int *listaUso)
{

	// Controllo se sono terminati i pacchi
	if (s == n) {

		// Se la soluzione corrente è migliore della best aggiorno la best
		if (corrente->altezza > best->altezza) {
			best->altezza = corrente->altezza;
			memcpy(best->pacchiTorre, corrente->pacchiTorre, n*sizeof(int));

			// In alternativa al memcpy si poteva utilizzare un ciclo for
			//for (int i = 0; i<n; i++){
			//	best->pacchi[i] = corrente->pacchi[i];
			//}
		}
		return;
	}

	// Per ogni pacco a disposizione
	for (int i = 0; i<n; i++) {
		
		// Se il pacco è già stato utilizzato salto al successivo
		if (listaUso[i] == 0){
			// Verifico se è possibile caricare il pacco
			if (verifica(corrente, s, pacchi, i)) {
				
				// Inserisco il pacco perchè rispetta i vincoli
				corrente->pacchiTorre[s] = i;
				corrente->altezza += pacchi[i].altezza;
				listaUso[i] = 1; 

				// Proseguo con il backtrack
				CostruisciTorre(n, pacchi, s + 1, corrente, best, listaUso);
				
				// Tolgo il pacco per provare a caricare il successivo alla prossima iterazione
				corrente->pacchiTorre[s] = -1;
				listaUso[i] = 0;
				corrente->altezza -= pacchi[i].altezza;
			}
			else{
				// Non posso inserire il pacco quindi proseguo senza caricarlo
				CostruisciTorre(n, pacchi, n, corrente, best, listaUso);
			}
		}
	}
}


int main(void)
{
	// Elenco dei pacchi che è possibile caricare (basta modificare questo array se si vuole modificare la lista dei pacchi che si possono utilizzare per costruire la torre)
	pacco elencoPacchi[] = { { .peso = 10, .altezza = 20, .limite = 40 }, { .peso = 10, .altezza = 10, .limite = 8 }, { .peso = 9, .altezza = 3, .limite = 5 } /*, { .peso = 10, .altezza = 1000, .limite = 20 }*/ };
	
	// Numero di pacchi a disposizione
	int n = sizeof(elencoPacchi) / sizeof(pacco);

	torre corrente = { .altezza = 0, .pacchiTorre = malloc(n*sizeof(int)) };
	torre best	   = { .altezza = 0, .pacchiTorre = malloc(n*sizeof(int)) };

	// Inizializzo la lista dei pacchi in torre corrente e torre best a -1
	for (int i = 0; i<n; i++){
		corrente.pacchiTorre[i] = -1;
		best.pacchiTorre[i] = -1;
	}

	int *listaUso;
	listaUso = calloc(n, sizeof(int)); // Nessun pacco utilizzato all'inizio -> listaUso inizializzata a zero

	printf("Lista di pacchi che si possono utilizzare (PESO, ALTEZZA, LIMITE):\n"); 
	for (int i = 0; i < n; i++){
		printf("(Pacco %d): %4d, %4d, %4d\n", i, elencoPacchi[i].peso, elencoPacchi[i].altezza,  elencoPacchi[i].limite);
	}
	printf("\n");

	// Chiamo la funzione di backtracking
	CostruisciTorre(n, elencoPacchi, 0, &corrente, &best, listaUso);

	if (best.altezza == 0)
		printf("Impossibile costruire la torre\n");
	else {
		printf("La torre piu' alta e' alta %d, ed e' formata dai seguenti pacchi (dall'alto al basso):\n", best.altezza);
		for (int i = 0; i < n; i++){
			if (best.pacchiTorre[i] >= 0){
				printf("%4d\n", best.pacchiTorre[i]);
			}
		}
	}

	free(corrente.pacchiTorre);
	free(best.pacchiTorre);
	free(listaUso);

	return 0; 
}

