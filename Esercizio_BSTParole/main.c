#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdio.h>
#include <string.h>

tree insertBinOrdDecr(element e, tree t){

	tree l = t;

	if (isEmptyTree(t))
		return consTree(e, emptyTree(), emptyTree());

	while (!isEmptyTree(t)) {
		if (isLess(root(t), e)){
			if (isEmptyTree(left(t))){
				t->left = consTree(e, emptyTree(), emptyTree());
				t = left(t);
			}
			t = left(t);
		}
		else {
			if (isEmptyTree(right(t))){
				t->right = consTree(e, emptyTree(), emptyTree());
				t = right(t);
			}
			t = right(t);
		}
	}

	return l;
}

void findMaxLenght(tree t, size_t *max,element* emax){
	if (!isEmptyTree(t)){
		
		if ((*max) < strlen(root(t))){
			*max = strlen(root(t));
			*emax = root(t);
		}

		findMaxLenght(left(t),max,emax);
		findMaxLenght(right(t),max,emax);
	}
}

void prinMaxlenght(tree t){
	size_t max = 0;
	element* emax=malloc(sizeof(element));
	findMaxLenght(t, &max,emax);

	printf("\nLa parola più lunga è:\t%s", *emax);
	free(emax);
}



void main(){
	FILE *f = fopen("parole.txt", "rt");
	if (f == NULL){
		fclose(f);
		return;
	}
	tree t = emptyTree();
	char tmp[MAX];
	while (fscanf(f, " %s", tmp) != EOF){
		t=insertBinOrd(tmp, t);
	}

	fclose(f);
	prinMaxlenght(t);



	FILE *g = fopen("parole.txt", "rt");
	if (g == NULL){
		fclose(g);
		return;
	}
	tree l = emptyTree();
	while (fscanf(g, " %s", tmp) != EOF){
		l = insertBinOrdDecr(tmp, l);
	}


	fclose(g);
}