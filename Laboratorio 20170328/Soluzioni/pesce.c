#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// metodo per la visualizzazione
void Visualizza(int v[][5], int n) {

	char Matrice1[5][20];
	char Matrice2[5][20];
	char Matrice3[5][20];
	char Matrice4[5][20];
	char Matrice5[5][20];
	int i, j, tmp, col;

	strcpy(Matrice1[0], "rossa");
	strcpy(Matrice1[1], "verde");
	strcpy(Matrice1[2], "bianca");
	strcpy(Matrice1[3], "gialla");
	strcpy(Matrice1[4], "blu");

	strcpy(Matrice2[0], "inglese");
	strcpy(Matrice2[1], "svedese");
	strcpy(Matrice2[2], "danese");
	strcpy(Matrice2[3], "norvegese");
	strcpy(Matrice2[4], "tedesco");

	strcpy(Matrice3[0], "te");
	strcpy(Matrice3[1], "caffe");
	strcpy(Matrice3[2], "latte");
	strcpy(Matrice3[3], "birra");
	strcpy(Matrice3[4], "acqua");

	strcpy(Matrice4[0], "Pall Mall");
	strcpy(Matrice4[1], "Dunhill's");
	strcpy(Matrice4[2], "Blends");
	strcpy(Matrice4[3], "Blue Master");
	strcpy(Matrice4[4], "Prince");

	strcpy(Matrice5[0], "cane");
	strcpy(Matrice5[1], "uccellini");
	strcpy(Matrice5[2], "gatti");
	strcpy(Matrice5[3], "cavalli");
	strcpy(Matrice5[4], "pesce");

	for (i = 0; i<n; i++) printf("%15s ", Matrice1[v[i][0]]);
	printf("\n");
	for (i = 0; i<n; i++) printf("%15s ", Matrice2[v[i][1]]);
	printf("\n");
	for (i = 0; i<n; i++) printf("%15s ", Matrice3[v[i][2]]);
	printf("\n");
	for (i = 0; i<n; i++) printf("%15s ", Matrice4[v[i][3]]);
	printf("\n");
	for (i = 0; i<n; i++){
		printf("%15s ", Matrice5[v[i][4]]);
		if (v[i][4] == 4)
			col = v[i][1];
	}

	printf("\n");
		printf("Il %s e' di proprieta' del %s\n", Matrice5[4], Matrice2[col]);
}


int Controlla11(int s, int v[][5]){
	//  11) L'uomo che ha i cavalli, vive vicino all'uomo che fuma le Dunhill's.
	//   v[s][4] == 3 allora v[s-1][3] == 1 OR v[s+1][3] == 1

	if (v[s][4] == 3) {
		if (s < 4 && v[s + 1][3] == 1)
			return 1;
		if (s > 0 && v[s - 1][3] == 1)
			return 1;
		else
			return 0;
	}
	else
		return 1;

}

int Controlla10(int s, int v[][5]){
	//  10) L'uomo che fuma le Blends, vive vicino a quello che ha i gatti.
	//   v[s][4] == 2 allora v[s-1][3] == 2 OR v[s+1][3] == 2

	if (v[s][4] == 2) {
		if (s < 4 && v[s + 1][3] == 2)
			return 1;
		if (s > 0 && v[s - 1][3] == 2)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}


int Controlla6(int s, int v[][5]){
	//  6) La persona che fuma le Pall Mall, ha degli uccellini.
	//   v[s][4] == 1 allora v[s][3] == 0

	if (v[s][4] == 1) {
		if (v[s][3] == 0)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

int Controlla2(int s, int v[][5]){
	//  2) Lo svedese ha un cane.
	//   v[s][4] == 0 allora v[s][1] == 1

	if (v[s][4] == 0) {
		if (v[s][1] == 1)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

void Permutazioni5(int n, int s, int v[][5], int *num){

	int i, j, tmp;

	if (s == n) {
		Visualizza(v, n);
		return;
	}

	for (i = s; i<n; i++){
		//scambio
		tmp = v[s][4];
		v[s][4] = v[i][4]; 
		v[i][4] = tmp;
		if (Controlla2(s, v) == 1 && Controlla6(s, v) == 1 && Controlla10(s, v) == 1 && Controlla11(s, v) == 1)
			Permutazioni5(n, s + 1, v, num);
		tmp = v[s][4]; 
		v[s][4] = v[i][4]; 
		v[i][4] = tmp;
	}

}


int Controlla15(int s, int v[][5]){
	// 15) L'uomo che fuma le Blends, ha un vicino che beve acqua.
	//   v[s][3] == 2 allora v[s-1][2] == 4 OR v[s+1][2] == 4

	if (v[s][3] == 2) {
		if (s < 4 && v[s + 1][2] == 4)
			return 1;
		if (s > 0 && v[s - 1][2] == 4)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

int Controlla12(int s, int v[][5]){
	//12) L'uomo che fuma le Blue Master, beve birra.
	//   v[s][3] == 3 allora v[s][2] == 3

	if (v[s][3] == 3) {
		if (v[s][2] == 3)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}


int Controlla7(int s, int v[][5]){
	// 7) Il proprietario della casa gialla fuma le Dunhill's.
	//   v[s][3] == 1 allora v[s][0] == 3

	if (v[s][3] == 1) {
		if (v[s][0] == 3)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

int Controlla13(int s, int v[][5]){
	// 13) Il tedesco fuma le Prince.
	//   v[s][3] == 4 allora v[s][1] == 4

	if (v[s][3] == 4) {
		if (v[s][1] == 4)
			return 1;
		else
			return 0;
	}
	else
		return 1;

}

void Permutazioni4(int n, int s, int v[][5], int *num){

	int i, tmp;

	if (s == n) {
		Permutazioni5(5, 0, v, num);
		return;
	}

	for (i = s; i<n; i++){
		tmp = v[s][3]; v[s][3] = v[i][3]; v[i][3] = tmp;
		if (Controlla13(s, v) == 1 && Controlla7(s, v) == 1 && Controlla12(s, v) == 1 && Controlla15(s, v) == 1)
			Permutazioni4(n, s + 1, v, num);
		tmp = v[s][3]; v[s][3] = v[i][3]; v[i][3] = tmp;
	}

}


int Controlla3(int s, int v[][5]){
	//  3) Il danese beve tè.
	//   v[s][2] == 0 allora v[s][1] == 2

	if (v[s][2] == 0) {
		if (v[s][1] == 2)
			return 1;
		else
			return 0;
	}
	else
		return 1;

}

int Controlla5(int s, int v[][5]){
	//  5) Il padrone della casa verde beve caffé.
	//   v[s][2] == 1 allora v[s][0] == 1

	if (v[s][2] == 1) {
		if (v[s][0] == 1)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

int Controlla8(int s, int v[][5]){
	//  8) L'uomo che vive nella casa centrale, beve latte.
	//   v[2][2] == 2 se non è così è errato

	if (s == 2) {
		if (v[s][2] == 2)
			return 1;
		else
			return 0;
	}
	else
		return 1;

}


void Permutazioni3(int n, int s, int v[][5], int *num){
	int i, tmp;
	if (s == n) {
		Permutazioni4(5, 0, v, num);
		return;
	}
	for (i = s; i<n; i++){
		tmp = v[s][2]; v[s][2] = v[i][2]; v[i][2] = tmp;
		if (Controlla8(s, v) == 1 && Controlla3(s, v) == 1 && Controlla5(s, v) == 1)
			Permutazioni3(n, s + 1, v, num);
		tmp = v[s][2]; v[s][2] = v[i][2]; v[i][2] = tmp;
	}

}

int Controlla14(int s, int v[][5]){
	//  14) Il norvegese vive vicino alla casa blu.
	//    v[s][1] == 3 allora v[s-1][0] == 4 OR v[s+1][0] == 4

	if (v[s][1] == 3) {
		if (s < 4 && v[s + 1][0] == 4)
			return 1;
		if (s > 0 && v[s - 1][0] == 4)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}


int Controlla1(int s, int v[][5]){
	//  1) L'inglese vive in una casa rossa.
	//   v[s][1] == 0 allora v[s][0] == 0

	if (v[s][1] == 0) {
		if (v[s][0] == 0)
			return 1;
		else
			return 0;
	}
	else
		return 1;

}

int Controlla9(int s, int v[][5]){
	//  9) Il norvegese vive nella prima casa.
	//   v[0][1] == 3 se non è così è errato

	if (s == 0) {
		if (v[s][1] == 3)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

void Permutazioni2(int n, int s, int v[][5], int *num){

	int i, tmp;

	if (s == n) {
		Permutazioni3(5, 0, v, num);
		return;
	}
	for (i = s; i<n; i++){
		tmp = v[s][1]; v[s][1] = v[i][1]; v[i][1] = tmp;
		if (Controlla9(s, v) == 1 && Controlla1(s, v) == 1 && Controlla14(s, v) == 1)
			Permutazioni2(n, s + 1, v, num);
		tmp = v[s][1]; v[s][1] = v[i][1]; v[i][1] = tmp;
	}

}


int Controlla4(int s, int v[][5]){
	// 4) La casa verde è all'immediata sinistra della casa bianca.
	//   1 a sinistra di 2
	//   if v[s][0] == 2 then v[s-1][0] == 1

	if (v[s][0] != 2)
		return 1;
	if (s > 0 && v[s - 1][0] == 1)
		return 1;
	return 0;

}

void Permutazioni(int n, int s, int v[][5], int *num){
	int i, tmp;
	if (s == n) {
		Permutazioni2(5, 0, v, num);
		return;
	}
	for (i = s; i<n; i++){
		tmp = v[s][0]; v[s][0] = v[i][0]; v[i][0] = tmp;
		if (Controlla4(s, v) == 1)
			Permutazioni(n, s + 1, v, num);
		tmp = v[s][0]; v[s][0] = v[i][0]; v[i][0] = tmp;
	}

}

void main2(){

	int	v[5][5];
	int num = 1, i, j, n = 5;

	for (j = 0; j<n; j++)
		for (i = 0; i<n; i++)
			v[i][j] = i;

	Permutazioni(5, 0, v, &num);
	getchar();

}
