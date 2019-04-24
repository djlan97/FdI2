﻿//ESERCIZIO STAZIONI DI SERVIZIO

// Giovanni deve percorrere M chilometri in motocicletta. Prima di partire si segna la posizione delle n stazioni di servizio s0, s1, . . ., s n−1
// presenti lungo il percorso.Tali posizioni sono identificate dalle distanze (in chilometri) d0, d1, . ..dn−1 dove d0 è la distanza dal punto di 
// partenza alla stazione s0, e per i = 1, . . ., n − 1 è la distanza fra le stazioni si−1 e si. Inoltre, per i = 0, . . ., n − 1, pi indica il 
// prezzo (al litro) praticato nella stazione si.

// La motocicletta consuma 0.05 litri per chilometro e ha un serbatoio di 30 litri inizialmente pieno. Giovanni decide di riempire totalmente il 
// serbatoio ogni volta che si ferma in una stazione di servizio.

// Scrivere una procedura

// void pianifica(double M, int n, double *d, double *p, int s, double dist, piano *c, piano *b)

// che dati gli array delle distanze d e dei prezzi p stampi l’elenco delle stazioni di servizio in cui si deve fermare per minimizzare la spesa per 
// il carburante (si ignori il valore del carburante che rimane nel serbatoio al termine del viaggio). I parametri passati alla funzione sono
// dettagliati  di seguito:

// M: km totali da percorrere,
// n: numero delle stazioni lungo il percorso,
// d: array delle distanze tra le stazioni, 
// p: prezzo del carburante nelle stazioni, 
// s: posizione/stazione corrente (a che livello dell'albero di backtracking si trova la funzione corrente),
// dist: distanza percorsa attualmente
// c: piano attuale
// b: miglior piano

// Inoltre il tipo piano è definito come segue: 
// typedef struct {
//		double costo;
//		int *stazione; 
// } piano;

// dove costo è il costo del piano e stazione è un puntatore ad un array binario (0-1) che contiene la lista delle fermate effettuate (1) e non (0)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h> // DBL_MAX 

typedef struct {
	double costo;	// costo del piano
	int *stazione;  // puntatore ad array binario (0-1) che contiene la lista delle fermate effettuate (1) e non (0)
} piano;

void pianifica(double M, int n, double *d, double *p, int s, double dist, piano *c, piano *b)
{
	// Controllo se posso arrivare a destinazione (Nota: 600km e' la distanza percorribile con un pieno 0.05 litri per chilometro con 30 litri di capacità del serbatoio)
	if (dist + 600 >= M) {
	
		// Se la suluzione corrente è migliore della best aggiorno la best
		if (c->costo < b->costo) {
			b->costo = c->costo;
			memcpy(b->stazione, c->stazione, n*sizeof(int));
			// In alternativa al memcpy si poteva utilizzare un ciclo for
			/*for (int i = 0; i < n; i++){
				b->stazione[i] = c->stazione[i];
			}*/
		}
		return;
	}

	double tmp = c->costo; // Salvo il costo attuale
	double parziale = 0;

	for (int i = s + 1; i < n; ++i) {
		parziale += d[i];
		if (parziale < 600){ // Con la benzina a disposizione posso arrivare fino alla stazione i
			c->stazione[i] = 1;
			c->costo += parziale*0.05*p[i]; // Aggiungo costo di rifornirmi in i

			// Scendo l'albero di backtracking
			pianifica(M, n, d, p, i, dist + parziale, c, b);

			c->costo = tmp;      // Ristabilisce vecchio c
			c->stazione[i] = 0;  // Non mi fermo alla stazione i-esima
		}
	}
}


int main(void)
{
	double M = 0; // Distanza totale da percorrere
	int n = 5; // Numero delle stazioni

	piano corrente = { .costo = 0, .stazione = calloc(n, sizeof(int)) };
	piano best = { .costo = DBL_MAX, .stazione = calloc(n, sizeof(int)) };

	double *distanza, *prezzo;
	distanza = malloc(n * sizeof(double));
	prezzo = malloc(n * sizeof(double));

	// Inizializzo i valori dei prezzi e dei km utilizzando una formula 
	for (int i = 0; i < n; i++){
		prezzo[i] = i + 35 - i*i;
		distanza[i] = 260 + i * 24;
		M += distanza[i];
		printf("Stazione %3d: km %.4f, prezzo %.4f\n", i, distanza[i], prezzo[i]);
	}

	// Chiamo la funzione di backtracking
	pianifica(M, n, distanza, prezzo, -1, 0, &corrente, &best);

	if (best.costo == DBL_MAX){
		printf("Impossibile raggiungere la meta\n");
	}
	else {
		printf("Conviene fare il pieno nelle seguenti stazioni (la spesa totale e' di %f):\n", best.costo);
		for (int i = 0; i < n; i++){
			if (best.stazione[i] == 1){
				printf("%d ", i);
			}
		}
	}
	return 0;
}

