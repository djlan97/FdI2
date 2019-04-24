/*#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void inverti(int v[], int i, int n){
	int c;
	if (i >= n / 2) return;
	else{
		c = v[n - i - 1];
		v[n - i - 1] = v[i];
		v[i] = c;
		inverti(v, i + 1, n);
	}
}

void main(void) {
	int v[100], i, n;
	printf("Inserire numero elementi vettore (max 100): ");
	scanf("%d", &n);
	for (i = 0; i<n; i++){
		printf("Inserire v[%d]: ", i);
		scanf("%d", &v[i]);
	}
	inverti(v, 0, n);
	printf("\nVettore invertito\n");
	for (i = 0; i<n; i++){
		printf("%d ", v[i]);
	}
	system("PAUSE");
}
*/