#include <stdlib.h>
#include <stdio.h>
#define N 3
typedef struct {
	unsigned peso;
	unsigned altezza;
	unsigned limite;
}pacco;

typedef struct{
	unsigned altezza;
	int *pacchiTorre;
}torre;

int verifica(int s,pacco *pacchi,torre *corrente,int i){
	unsigned somma = 0;
	
	for (int j = 0; j < s; ++j){
		somma += pacchi[corrente->pacchiTorre[j]].peso;
	}

	if (somma <= pacchi[i].limite){
		return 1;
	}
	else{
		return 0;
	}
}

void CostruisciTorre(int n, pacco *pacchi, int s, torre *corrente, torre *best, int *listaUso){
	if (s == n){
		if (corrente->altezza>best->altezza) {
			best->altezza = corrente->altezza;
			for (int i = 0; i<n; i++){
				best->pacchiTorre[i] = corrente->pacchiTorre[i];
			}
		}
		return;
	}

	for (int i = 0; i < n; ++i){
		if (listaUso[i] == 0){
			if (verifica(s,pacchi,corrente,i) == 1){
				corrente->pacchiTorre[s] = i;
				corrente->altezza += pacchi[i].altezza;
				listaUso[i] = 1;
				CostruisciTorre(n, pacchi, s + 1, corrente, best, listaUso);
				corrente->pacchiTorre[s] = -1;
				corrente->altezza -= pacchi[i].altezza;
				listaUso[i] = 0;
			}
			else{
				CostruisciTorre(n, pacchi, n, corrente, best, listaUso);
			}
		}
	}
}



int main(void){

	torre corrente, best;
	corrente.altezza = 0;
	best.altezza = 0;
	corrente.pacchiTorre = malloc(N*sizeof(int));
	best.pacchiTorre = malloc(N*sizeof(int));
	int n = N;
	pacco elencopacchi[N];
	int   listaUso[N];


	for (int i = 0; i<N; i++){
		corrente.pacchiTorre[i] = -1;
		best.pacchiTorre[i] = -1;
		listaUso[i] = 0;
	}


	elencopacchi[0].peso = 10;
	elencopacchi[0].altezza = 20;
	elencopacchi[0].limite = 40;

	elencopacchi[1].peso = 10;
	elencopacchi[1].altezza = 10;
	elencopacchi[1].limite = 8;

	elencopacchi[2].peso = 9;
	elencopacchi[2].altezza = 3;
	elencopacchi[2].limite = 5;

	CostruisciTorre(N, elencopacchi, 0, &corrente, &best,listaUso);
	

	if (best.altezza == 0)
		printf("Impossibile costruire la torre");
	else {
		printf("\nElenco pacchi (dall'alto al basso): ");
		for (int i = 0; i<n; i++)
		if (best.pacchiTorre[i] >= 0)
			printf("\n(%d): %d", i, best.pacchiTorre[i]);
	}

	getchar();



	free(corrente.pacchiTorre);
	free(best.pacchiTorre);

	return 0;
}