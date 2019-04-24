#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ever (;;)

// Somma dei numeri fino ad n in maniera ricorsiva

unsigned SommaRicorsivaFinoA(unsigned n){

	if (n == 1)
		return 1;
	else
		return n + SommaRicorsivaFinoA(n - 1); 

}

int ProdottoRicorsivtoTra(int a, int b){
	if (b == 0)
		return 0;
	else{
		if (a > 0){
			if (b > 0){
				// a > 0 && b > 0
				return a + ProdottoRicorsivtoTra(a, --b);
			}
			else{
				// a > 0 && b < 0
				return -1*a + ProdottoRicorsivtoTra(a, ++b);
			}
		}
		else{
			if (b > 0){
				// a < 0 && b > 0
				return a + ProdottoRicorsivtoTra(a, --b);
			}
			else{
				// a < 0 && b < 0
				return -1*a + ProdottoRicorsivtoTra(a, ++b);
			}
		}
	
	}
}

// n = passi di fibonacci che si vogliono eseguire	
unsigned FibonacciRicorsivo(unsigned n){
	if (n < 2){
		return n;
	}
	else{
		return FibonacciRicorsivo(n - 1) + FibonacciRicorsivo(n - 2);
	}
}

unsigned long FattorialeRicorsivo(unsigned long N){

	if (N == 0){
		return 1; 
	}
	else{
		return N * FattorialeRicorsivo(N-1);
	}
}

int RicercaMassimoRicorsiva(int *vet, size_t pos){

	if (pos == 0){
		return vet[0];
	}
	
	--pos;
	int max_c = RicercaMassimoRicorsiva(vet, pos);
	if (max_c > vet[pos]){
		return max_c;
	}
	else{
		return vet[pos];
	}
}

int DivisioneInteraRicorsivaTra(int a, int b){

	if (abs(a) < abs(b)){
		return 0;
	}
	else{
		if (a > 0){
			if (b > 0){
				// a > 0 && b > 0
				return 1 + DivisioneInteraRicorsivaTra(a - b, b);
			}
			else{
				// a > 0 && b < 0
				return -1 + DivisioneInteraRicorsivaTra(a + b, b);
			}
		}
		else{
			if (b > 0){
				// a < 0 && b > 0
				return -1 + DivisioneInteraRicorsivaTra(a + b, b);
			}
			else{
				// a < 0 && b < 0
				return +1 + DivisioneInteraRicorsivaTra(a - b, b);
			}
		}
	}
}

int main(void){
	
	char *menuVoci[] = { "0: esci",
						 "1: somma ricorsiva dei numeri interi da 1 a N (stdin)", 
						 "2: visualizza i primi N (stdin) numeri della successione di Fibonacci", 
						 "3: ricerca il massimo in un vettore V (stdin) di interi con segno",
						 "4: prodotto ricorsivo degli interi A x B (stdin)",
						 "5: calcolare il fattoriale di un numero N (stdin)",
						 "6: calcolare la divisione intera fra A e B (stdin)",
						};
	int menuId = 0;

	for ever{
		printf("**** SCEGLI UNA VOCE DAL MENU: ****\n");
		for (size_t i = 0; i < sizeof(menuVoci) / sizeof(menuVoci[0]); ++i){
			printf(menuVoci[i]); printf("\n");
		}
		scanf("%d", &menuId); 

		int N, A, B;
		int *vet; 

		switch (menuId)
		{
		case 0:
			return 0; // Termina il programma
			break; // Inutile
		case 1:
			do{
				printf("Inserisci un valore intero N maggiore di 0\n");
				scanf("%d", &N);
			} while (N < 1);

			printf("La somma dei numeri da 1 a %d e': %d\n", N,		SommaRicorsivaFinoA(N));
			break;
		case 2:
			do{
				printf("Inserisci un valore intero N maggiore di 0\n");
				scanf("%d", &N);
			} while (N < 1);

			for (int i = 1; i < N + 1; ++i){
				printf("%d ", FibonacciRicorsivo(i));
			}
			printf("\n");
			break;
		case 3:
			do{
				printf("Quanti elementi vuoi inserire nel vettore?");
				scanf("%d", &N);
			} while (N < 2);

			vet = (int *)malloc(N*sizeof(int));

			for (int i = 0; i < N; ++i){
				printf("Inserisci il valore %d del vettore: ", i);
				scanf("%d", &vet[i]);
			}

			printf("Il massimo del vettore e': %d \n", RicercaMassimoRicorsiva(vet, N));
			break;
		case 4:
			printf("Inserisci un valore intero A \n");
			scanf("%d", &A);
			printf("Inserisci un valore intero B \n");
			scanf("%d", &B);

			printf("%d x %d = %d\n", A,B,ProdottoRicorsivtoTra(A,B));
			break;
		case 5:
			do{
				printf("Inserisci un valore intero positivo N di cui calcolare il fattoriale \n");
				scanf("%d", &N);
			} while (N < 0);

			printf("%d! = %d\n", N, FattorialeRicorsivo(N));
			break;
		case 6:
			do{
				printf("Inserisci un valore intero A \n");
				scanf("%d", &A);
				printf("Inserisci un valore intero B diverso 0 \n");
				scanf("%d", &B);
			} while (B == 0);

			printf("%d / %d = %d\n", A, B, DivisioneInteraRicorsivaTra(A, B));
			break;
		default:
			break;
		}
	}


}

