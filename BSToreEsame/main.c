#include "tree.h"
#include <stdio.h>

tree insertBinOrdid(element e, tree t){

	tree l = t;

	if (isEmptyTree(t))
		return consTree(e, emptyTree(), emptyTree());

	while (!isEmptyTree(t)) {
		if (root(t).id>=e.id){
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

treeInt consTreeInt(int e, treeInt l, treeInt r){
	treeInt t = (nodeInt*)malloc(sizeof(nodeInt));
	t->value = e;
	t->left = l;
	t->right = r;
	return t;
}


treeInt insertBinOrdInt(int e, treeInt t){

	treeInt l = t;

	if (t==NULL)
		return consTreeInt(e, NULL, NULL);

	while (t!=NULL) {
		if (t->value>=e){
			if (t->left==NULL){
				t->left = consTreeInt(e, NULL, NULL);
				t = t->left;
			}
			t = t->left;
		}
		else {
			if (t->right == NULL){
				t->right = consTreeInt(e, NULL, NULL);
				t = t->right;
			}
			t = t->right;
		}
	}

	return l;
}

treeInt funz(tree t,treeInt tree_i,int radice){
	if (t!=NULL){
		if (t->value.id%radice == 0){
			tree_i = insertBinOrdInt(t->value.id, tree_i);
		}
		tree_i=funz(t->left,tree_i,radice);
		tree_i=funz(t->right,tree_i,radice);
	}
	return tree_i;
}

tree funz2(tree t, tree f){
	if (!isEmptyTree(t)){
		f=funz2(left(t),f);
		f=funz2(right(t),f);
		f = insertBinOrdid(root(t), f);
	}
	return f;
}

void main(){
	tree t = emptyTree();
	element e;
	FILE *f = fopen("prova.txt", "rt");
	if (f == NULL){
		return;
	}
	while (fscanf(f, " %s %s %d %d", e.cognome, e.nome, &e.eta, &e.id)!=EOF){
		t = insertBinOrd(e,t);
	}
	fclose(f);
	treeInt tree_i = NULL;
	tree_i = funz(t, tree_i,root(t).id);
	tree t2 = NULL;
	t2=funz2(t, t2);
}