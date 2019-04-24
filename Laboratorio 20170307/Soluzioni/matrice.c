#define _CRT_SECURE_NO_WARNINGS
#define N 4
#include<stdio.h>

typedef enum{ false, true }boolean;


boolean simmetricaDP(int matr[][N], int i, int j){
	//fine della ricorsione
	if (i == 0) return true;

	// fine esame di una riga: si passa alla riga di indice inferiore
	if (j<0) return (simmetricaDP(matr, i - 1, i - 1));

	// elemento sulla diagonale principale: si passa alla colonna di indice inferiore
	if (i == j) return (simmetricaDP(matr, i, j - 1));

	// elemento della triangolare inferiore da confrontare col simmetrico della triangolare superiore
	return (matr[i][j] == matr[j][i]) && (simmetricaDP(matr, i, j - 1));
}


void main(void){
	int mat[N][N], i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++){
			printf("Inserisci Mat[%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
	if (simmetricaDP(mat, N - 1, N - 1) == true)
		printf("\nMatrice simmetrica rispetto alla diagonale principale\n");
	else
		printf("\nMatrice nonsimmetrica rispetto alla diagonale principale\n");

}



