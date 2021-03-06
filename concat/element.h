#if !defined ELEMENT_H
#define ELEMENT_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*DEFINIZIONI*/

typedef struct{
	long val;
	char str[50];
}nonloso;

typedef nonloso element;
typedef bool boolean;

/*DICHIARAZIONI FUNZIONI*/
extern boolean isEqual(element e1, element e2);
extern boolean isLess(element e1, element e2);
extern element copy(element e);
extern element getElement();
extern void printElement(element el);

#endif/*ELEMENT_H*/