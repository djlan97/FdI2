#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#define ARRAY_MONETE 6

void cambio(int monete[], int n, int valore)
{
	int i;
	int ris[ARRAY_MONETE] = { 0 };
	int min = 0;

	for (i = 0; i < ARRAY_MONETE; i++)
	{
			ris[i] = valore / monete[i];
			valore = valore%monete[i];
			min = min + ris[i];
	}

	printf("Minimo monete %d \n", min);
	//printf("Minimo monete %d \n", min_monete[valore]);
	for (int i = 0; i < ARRAY_MONETE; ++i)
		//printf("%d: %d\n", monete[i], count[valore][i]);
		printf("%d: %d\n", monete[i], ris[i]);

}

int main()
{
	int budget;
	printf("Inserisci il budget\n");
	scanf("%d", &budget);
	int monete[ARRAY_MONETE] = {50, 20, 10, 5, 2, 1};
	cambio(monete, ARRAY_MONETE, budget);
};