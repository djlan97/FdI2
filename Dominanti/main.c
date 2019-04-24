#include "tree.h"

int contaDominanti(tree t){
	if (isEmptyTree(t) || (isEmptyTree(left(t)) && isEmptyTree(right(t)))) return 0;
	if (!isEmptyTree(left(t)) && !isEmptyTree(right(t))){
		if (root(left(t)) + root(right(t)) < root(t)) return 1 + contaDominanti(left(t)) + contaDominanti(right(t));
		else
			return 0 + contaDominanti(left(t)) + contaDominanti(right(t));
	}

	if (!isEmptyTree(left(t)) && isEmptyTree(right(t))){
		if (root(left(t)) < root(t)){
			return 1 + contaDominanti(left(t));
		}
		else{
			return 0 + contaDominanti(left(t));
		}
	}

	if (isEmptyTree(left(t)) && !isEmptyTree(right(t))){
		if (root(right(t)) < root(t)){
			return 1 + contaDominanti(right(t));
		}
		else{
			return 0 + contaDominanti(right(t));
		}

	}
	return 0;

}

void main(){
	tree t = emptyTree();
	t = insertBinOrd(9, t);
	t = insertBinOrd(4, t);
	t = insertBinOrd(12, t);
	t = insertBinOrd(2, t);
	t = insertBinOrd(8, t);
	t = insertBinOrd(1, t);
	t = insertBinOrd(3, t);
	t = insertBinOrd(6, t);
	t = insertBinOrd(5, t);
	t = insertBinOrd(7, t);
	t = deleteTree(4, t);
}