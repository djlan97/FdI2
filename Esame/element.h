#if !defined ELEMENT_H
#define ELEMENT_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*DEFINIZIONI*/

typedef struct{
	char str[20];
	int numero;

}Struttura2;

typedef Struttura2 element2;

typedef struct{
	char cognome[20];
	char nome[20];
	char str[20];
	int numero;

}Struttura;

typedef Struttura element;
typedef bool boolean;

/*DICHIARAZIONI FUNZIONI*/
extern boolean isEqual(element e1, element e2);
extern boolean isLess(element e1, element e2);
extern element copy(element e);
extern element getElement();
extern void printElement(element el);

#endif/*ELEMENT_H*/