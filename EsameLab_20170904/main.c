#define MAX 5
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
typedef struct{
	int zona;
	char colore[10];
}zona;

void printzona(zona *z){
	printf("zona %d %s\n", (*z).zona, (*z).colore);
}

int controlla(zona zone[5]){
	if (strcmp(zone[0].colore, zone[1].colore) == 0 || strcmp(zone[0].colore, zone[2].colore) == 0 || strcmp(zone[0].colore, zone[3].colore) == 0 || strcmp(zone[0].colore, zone[4].colore) == 0){
		return 0;
	}
	if (strcmp(zone[1].colore, zone[2].colore) == 0 || strcmp(zone[1].colore, zone[3].colore) == 0 || strcmp(zone[1].colore, zone[4].colore) == 0){
		return 0;
	}
	if (strcmp(zone[2].colore, zone[3].colore) == 0){
		return 0;
	}
	if (strcmp(zone[3].colore, zone[4].colore) == 0){
		return 0;
	}
	return 1;
}

void funzione(zona zone[5], int count, char colori[4][10]){
	if (count == 5){
		if (controlla(zone)){
			for (int i = 0; i < 5; i++){
				printzona(&zone[i]);
				
			}
			printf("\n\n");
		
		}
		return;
	}
	for (int j = 0; j < 4; j++){
			strcpy(zone[count].colore, colori[j]);
			funzione(zone, count + 1, colori);
	}

}

void main(){
	char colori[4][10];
	strcpy(colori[0], "rosso");
	strcpy(colori[1], "verde");
	strcpy(colori[2], "blu");
	strcpy(colori[3], "giallo");
	zona zone[5];
	zone[0].zona = 1;
	zone[1].zona = 2;
	zone[2].zona = 3;
	zone[3].zona = 4;
	zone[4].zona = 5;
	funzione(zone, 0, colori);
}