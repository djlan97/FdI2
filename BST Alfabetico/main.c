#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include "tree.h"
#include <string.h>
#include <stdio.h>

void stampaDecr(tree t){
	if (!isEmptyTree(t)){
		stampaDecr(right(t));
		stampaDecr(left(t));		
		printf(" %s\n", root(t));		
	}
}

void trovaMax(tree t,element max){
	if (isEmptyTree(t)){
		return;
	}
	if (strlen(root(t)) > strlen(max)){
		strcpy(max, root(t));
	}
	trovaMax(left(t),max);
	trovaMax(right(t),max);
}

void main(){
	tree t = emptyTree();
	FILE *f = fopen("file.txt", "rt");
	if (f == NULL){
		return;
	}
	char e[MAX];
	while (fscanf(f, " %s", e)!=EOF){
		t = insertBinOrd(e, t);
	}
	fclose(f);
	trovaMax(t, e);
	printf("La parola più lunga è:\n%s\n", e);
	printf("Le parole in ordine decrescente sono:\n");
	stampaDecr(t);

}