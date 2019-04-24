#if !defined element22_H
#define element22_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*DEFINIZIONI*/
typedef int element2;
typedef bool boolean;

/*DICHIARAZIONI FUNZIONI*/
extern boolean isEqual2(element2 e1, element2 e2);
extern boolean isLess2(element2 e1, element2 e2);
extern element2 copy2(element2 e);
extern element2 getelement2();
extern void printelement2(element2 el);

#endif/*element22_H*/