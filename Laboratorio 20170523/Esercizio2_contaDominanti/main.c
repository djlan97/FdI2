#include "tree.h"
#include <stdio.h>

int contaDominanti(tree t){	
	if (!empty(right(t)) && empty(left(t))){ 
		return 0 + contaDominanti(right(t));
	}
	if (empty(right(t)) && !empty(left(t))) { 
		return 1 + contaDominanti(left(t));
	}
	if (!empty(left(t)) && !empty(right(t))){
		if (!isLess(root(t),root(left(t)) + root(right(t)))){
			return 1 + contaDominanti(left(t)) + contaDominanti(right(t));
		}
		else{
			return 0 + contaDominanti(left(t)) + contaDominanti(right(t));
		}
	}
	return 0;
}



void main(){
	FILE *f = fopen("Text.txt", "rt");
	if (f == NULL){
		return;
	}
	tree t = emptyTree();
	element e;
	while (fscanf(f, " %d", &e) > 0){
		t = insertBinOrd(e, t);
	}

	int num = contaDominanti(t);
}