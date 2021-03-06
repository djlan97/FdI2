#if !defined ELEMENT_H
#define ELEMENT_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/*DEFINIZIONI*/
typedef struct listint{
	char interesse[15];
	struct listint *next;
}interesse;

typedef interesse* listInt;
typedef struct{
	char nome[15];
	listInt l_interessi;
}element;
typedef bool boolean;

/*DICHIARAZIONI FUNZIONI*/
extern boolean isEqual(element e1, element e2);
extern boolean isLess(element e1, element e2);
extern element copy(element e);
extern element getElement();
extern void printElement(element el);

#endif/*ELEMENT_H*/