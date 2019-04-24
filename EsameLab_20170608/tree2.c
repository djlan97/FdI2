#include "tree2.h"

/*DEFINIZIONI*/

/*PRIMITIVE*/
boolean isEmptytree2(tree2 t){
	return (t == NULL);
}

tree2 emptytree2(void){
	return NULL;
}

element2 root2(tree2 t){
	if (isEmptytree2(t)) abort();
	else return t->value;
}

tree2 left2(tree2 t){
	if (isEmptytree2(t)) return NULL;
	else return t->left;
}

tree2 right2(tree2 t){
	if (isEmptytree2(t)){
		return NULL;
	}
	else return t->right;
}

tree2 constree2(element2 e, tree2 l, tree2 r){
	tree2 t = (node2*)malloc(sizeof(node2));
	t->value = e;
	t->left = l;
	t->right = r;
	return t;
}

/*NON PRIMITIVE*/
void preOrder2(tree2 t){
	if (!isEmptytree2(t)){
		printf("1t");
		printelement2(root2(t));
		preOrder2(left2(t));
		preOrder2(right2(t));
	}
}

void inOrder2(tree2 t){
	if (!isEmptytree2(t)){
		inOrder2(left2(t));
		printf("\t");
		printelement2(root2(t));
		inOrder2(right2(t));
	}
}

void postOrder2(tree2 t){
	if (!isEmptytree2(t)){
		postOrder2(left2(t));
		postOrder2(right2(t));
		printf("t");
		printelement2(root2(t));
	}
}

boolean membertree2(element2 e, tree2 t){
	if (isEmptytree2(t)) return false;
	else if (isEqual2(e, root2(t))) return true;
	else return (membertree2(e, left2(t)) || membertree2(e, right2(t)));
}

int height2(tree2 t){
	if (isEmptytree2(t)) return 0;
	else{
		int hl = height2(left2(t)), hr = height2(right2(t));
		return 1 + (hl > hr ? hl : hr);
	}
}

/*BST*/

tree2 insertBinOrd2(element2 e, tree2 t){

	tree2 l = t;

	if (isEmptytree2(t))
		return constree2(e, emptytree2(), emptytree2());

	while (!isEmptytree2(t)) {
		if (!isLess2(root2(t), e)){
			if (isEmptytree2(left2(t))){
				t->left = constree2(e, emptytree2(), emptytree2());
				t = left2(t);
			}
			t = left2(t);
		}
		else {
			if (isEmptytree2(right2(t))){
				t->right = constree2(e, emptytree2(), emptytree2());
				t = right2(t);
			}
			t = right2(t);
		}
	}

	return l;
}

boolean membertree2Ord(element2 e, tree2 t){
	if (isEmptytree2(t)) return false;
	else
	if (isEqual2(e, root2(t))) return true;
	else
	if (isLess2(e, root2(t))) return membertree2Ord(e, left2(t));
	else return membertree2Ord(e, right2(t));

}