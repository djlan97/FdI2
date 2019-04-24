#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include "tree2.h"

#include <stdio.h>
#define MAX 20

tree2 postOrder(tree2 l,tree t,int root){
	if (!isEmptyTree(t)){
		
		l=postOrder(l,left(t),root);
		l=postOrder(l,right(t),root);
		int tmp = t->value.cod;
		if (tmp%root == 0){
			l = insertBinOrd2(tmp, l);
		}
		
	}
	return l;
}



void main(){
	FILE *f = fopen("prova.txt", "rt");
	if (f == NULL){
		fclose(f);
		return;
	}
	tree t = emptyTree();
	element tmp;

	while (fscanf(f, " %s", tmp.matricola) != EOF){
		fscanf(f, " %s", tmp.cognome);
		fscanf(f, " %s", tmp.nome);
		fscanf(f, " %d", &tmp.cod);
		t = insertBinOrd(tmp, t);
	}
	fclose(f);


	tree2 l=NULL;
	element2 root = (t->value.cod)*2;
	l=postOrder(l,t, root);

}