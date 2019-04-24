#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 3

typedef struct{
	int Codice;
	float Peso;
	float Prezzo;
} Gioielli;

void sort(Gioielli *g, int n){
	int ordinato = 0;
	while (n > 0 && !ordinato){
		ordinato = 1;
		for (int i = 0; i < n; i++){
			if (g[i].Prezzo / g[i].Peso < g[i + 1].Prezzo / g[i + 1].Peso){
				Gioielli tmp = g[i];
				g[i]=g[i + 1];
				g[i + 1] = tmp;
				ordinato = 0;
			}
		}


		n--;
	}
}

void riempi(Gioielli *g, int *bin, int n,float peso_max){
	for (int i = 0; i < n; ++i){
		if (peso_max - g[i].Peso >= 0){
			peso_max -= g[i].Peso;
			bin[i] = 1;
		}
	}
}

void main(){
	Gioielli v[N];
	Gioielli g;
	for (int i = 0; i < N; ++i){
		printf("\nInserisci codice:\t");
		scanf(" %d", &g.Codice);
		printf("\nInserisci peso:\t");
		scanf(" %f", &g.Peso);
		printf("\nInserisci #presso:\t");
		scanf(" %f", &g.Prezzo);
		v[i] = g;
	}

	sort(v, N);
	/*float r[N];
	for (int i = 0; i < N; i++){
		r[i] = v[i].Prezzo / v[i].Peso;
	}*/

	float w = 50;
	int ret[N] = {0,0,0};
	riempi(v, ret, N, w);

}