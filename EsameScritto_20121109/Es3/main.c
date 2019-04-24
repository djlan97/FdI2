#define _CRT_SECURE_NO_WARNINGS

#include "list.h"
#include <stdio.h>
#include <string.h>

int checkInteressi(listInt l1, listInt l2){
	int count = 0;
	listInt rootl2 = l2;
	while (l1 != NULL){
		while (l2 != NULL){
			if (strcmp(l1->interesse, l2->interesse) == 0){
				count++;
				break;
				
			}

			l2 = l2->next;
		}
		if (count == 2){
			return 1;
		}
		l2 = rootl2;
		l1 = l1->next;
	}
	return 0;
}

void visualizzaCoppie(list l){
	while (l != NULL){
		list succ = l->next;
		while (succ!=NULL){
			if (checkInteressi(l->value.l_interessi, succ->value.l_interessi)){
				printf(" %s e %s\n", l->value.nome, succ->value.nome);
			}
			succ = succ->next;
		}
		l = l->next;
	}
}

int lenListInt(listInt l){
	int count = 0;
	while (l != NULL){
		count++;
		l = l->next;
	}

	return count;
}

void visualizzaMax(list l){
	int max = 0;
	list l_max = NULL;
	while (l != NULL){
		if (lenListInt(l->value.l_interessi) > max){
			max = lenListInt(l->value.l_interessi);
			l_max = l;
		}

		l = l->next;
	}
	printf("Utente con maggior numero di interessi:\n%s con %d interessi\n", l_max->value.nome, max);
}

void main(){
	FILE *f = fopen("utenti.txt", "rt");
	if (f == NULL){
		return;
	}
	list l = NULL;
	element e;
	char str[15];
	while (fscanf(f," %[^:]:",e.nome)!=EOF){
		e.l_interessi = NULL;
		l = cons(e, l);
		while (fscanf(f, " %[^,\n]", str)!=EOF){
			l->value.l_interessi = consListInt(str, l->value.l_interessi);
			if (fgetc(f) == '\n'){
				break;
			}
		}
	}

	visualizzaMax(l);
	visualizzaCoppie(l);
}