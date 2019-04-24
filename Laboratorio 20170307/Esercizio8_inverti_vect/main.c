#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>

void scambia_vect(int *v, int n){
	if (n != 0 && n != 1){
		int tmp = v[0];
		v[0] = v[n - 1];
		v[n - 1] = tmp;
		scambia_vect(v + 1, n - 2);
	}
}

int main(void){
	int v[100], i, n;
	printf("Inserire numero elementi vettore (max 100): ");
	scanf("%d", &n);
	for (i = 0; i<n; i++){
		printf("Inserire v[%d]: ", i);
		scanf("%d", &v[i]);
	}

	scambia_vect(v, n);

	printf("\nVettore invertito\n");
	for (i = 0; i<n; i++){
		printf("%d ", v[i]);
	}
	system("PAUSE");

	return EXIT_SUCCESS;
}