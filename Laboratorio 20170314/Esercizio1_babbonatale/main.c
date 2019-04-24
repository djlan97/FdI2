#include <stdio.h>
#define N 10

void RiempiSlitta(int n,int s,int v[],int peso[],int best[],int *max,int count,int sommaparziale,int capienza){
	if (s == n){

		if (count > *max){
			*max = count;
			for (int i = 0; i < n; i++) best[i]=v[i];
		}
		return;
	}
	v[s] = 0;
	RiempiSlitta(n, s + 1, v, peso, best, max, count, sommaparziale, capienza);
	if (sommaparziale + peso[s] <= capienza){
		v[s] = 1;
		sommaparziale += peso[s];
		count++;
		RiempiSlitta(n, s + 1, v, peso, best, max, count, sommaparziale, capienza);
	}
}

int main(void){
	int v[N];
	int peso[N] = {1,2,3,4,5,6,7,8,9,10};
	int best[N];
	int max = 0;
	RiempiSlitta(N, 0, v, peso, best, &max, 0, 0, 80);

	for (int i = 0; i < N; i++){
		best[i] = 0;
	}

	printf("Il numero massimo di regali e' %d", max);
}