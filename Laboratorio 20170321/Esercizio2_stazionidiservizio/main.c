#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <float.h>
#define N 5


typedef struct{
	double costo;
	int *stazione;
}piano;

void controllo(int s, double dist, double *d){


}


void pianifica(double M, int n, double *d, double *p, int s, double dist, piano *c, piano *b){
	if (dist+600==M){

		if (c->costo < b->costo){
			b->costo = c->costo;
		}


		return;
	}


	c->stazione[s] = 0;
	pianifica(M, n, d, p, s + 1, dist, c, b);

	if (1){

		c->stazione[s] = 1;
		c->costo += p[s]*0.05;
		pianifica(M, n, d, p, s + 1, dist, c, b);
		

	}

	c->stazione[s] = 0;


}

void main(void){

	double M = 0;
	
	piano corrente, best;
	corrente.stazione = malloc(N*sizeof(int));
	best.stazione = malloc(N*sizeof(int));
	int n = N;
	double distanza[N], prezzo[N];

	for (int i = 0; i < N; i++){
		corrente.stazione[i] = 0;
		best.stazione[i] = 0;
		prezzo[i] = i + 35 - i*i;
		distanza[i] = 260 + i * 24;
		M += distanza[i];
		printf("\nstazione %d,  km %f, prezzo %f", i, distanza[i], prezzo[i]);
	}

	corrente.costo = 0;
	best.costo = DBL_MAX;

	pianifica(M, n, distanza, prezzo, 0, 0, &corrente, &best);

	if (best.costo == DBL_MAX)
		printf("\nImpossibile raggiungere la meta");
	else {
		printf("\nConviene fare il pieno nelle stazioni (spesa totale %f): ", best.costo);
		for (int i = 0; i < n; i++)
		if (best.stazione[i] == 1)
			printf("\n%d", i);
	}

}