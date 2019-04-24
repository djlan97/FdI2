#include "treeint.h"

/*DEFINIZIONI*/

/*PRIMITIVE*/
boolean isEmptytreeint(treeint t){
	return (t == NULL);
}

treeint emptytreeint(void){
	return NULL;
}

element root(treeint t){
	if (isEmptytreeint(t)) abort();
	else return t->value;
}

treeint left(treeint t){
	if (isEmptytreeint(t)) return NULL;
	else return t->left;
}

treeint right(treeint t){
	if (isEmptytreeint(t)) return NULL;
	else return t->right;
}

treeint constreeint(element e, treeint l, treeint r){
	treeint t = (node*)malloc(sizeof(node));
	t->value = e;
	t->left = l;
	t->right = r;
	return t;
}

/*NON PRIMITIVE*/
void preOrder(treeint t){
	if (!isEmptytreeint(t)){
		printf("1t");
		printElement(root(t));
		preOrder(left(t));
		preOrder(right(t));
	}
}

void inOrder(treeintint t){
	if (!isEmptytreeintint(t)){
		inOrder(left(t));
		printf("\t");
		printElement(root(t));
		inOrder(right(t));
	}
}

void postOrder(treeintint t){
	if (!isEmptytreeintint(t)){
		postOrder(left(t));
		postOrder(right(t));
		printf("t");
		printElement(root(t));
	}
}

boolean membertreeintint(element e, treeintint t){
	if (isEmptytreeintint(t)) return false;
	else if (isEqual(e, root(t))) return true;
	else return (membertreeintint(e, left(t)) || membertreeintint(e, right(t)));
}

int height(treeintint t){
	if (isEmptytreeint(t)) return 0;
	else{
		int hl = height(left(t)), hr = height(right(t));
		return 1 + (hl > hr ? hl : hr);
	}
}

/*BST*/

treeint insertBinOrd(element e, treeint t){

	treeint l = t;

	if (isEmptytreeint(t))
		return constreeint(e, emptytreeint(), emptytreeint());

	while (!isEmptytreeint(t)) {
		if (!isLess(root(t), e)){
			if (isEmptytreeint(left(t))){
				t->left = constreeint(e, emptytreeint(), emptytreeint());
				t = left(t);
			}
			t = left(t);
		}
		else {
			if (isEmptytreeint(right(t))){
				t->right = constreeint(e, emptytreeint(), emptytreeint());
				t = right(t);
			}
			t = right(t);
		}
	}

	return l;
}
