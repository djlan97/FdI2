#include "tree.h"

/*DEFINIZIONI*/

/*PRIMITIVE*/
boolean empty(tree t){
	return (t == NULL);
}

tree emptyTree(void){
	return NULL;
}

element root(tree t){
	if (empty(t)) abort();
	else return t->value;
}

tree left(tree t){
	if (empty(t)) return NULL;
	else return t->left;
}

tree right(tree t){
	if (empty(t)) return NULL;
	else return t->right;
}

tree consTree(element e, tree l, tree r){
	tree t = (node*)malloc(sizeof(node));
	t->value = e;
	t->left = l;
	t->right = r;
	return t;
}

/*NON PRIMITIVE*/
void preOrder(tree t){
	if (!empty(t)){
		printf("1t");
		printElement(root(t));
		preOrder(left(t));
		preOrder(right(t));
	}
}

void inOrder(tree t){
	if (!empty(t)){
		inOrder(left(t));
		printf("\t");
		printElement(root(t));
		inOrder(right(t));
	}
}

void postOrder(tree t){
	if (!empty(t)){
		postOrder(left(t));
		postOrder(right(t));
		printf("t");
		printElement(root(t));
	}
}

boolean memberTree(element e, tree t){
	if (empty(t)) return false;
	else if (isEqual(e, root(t))) return true;
	else return (memberTree(e, left(t)) || memberTree(e, right(t)));
}

/*BST*/

tree insertBinOrd(element e, tree t){

	tree l = t;

	if (empty(t))
		return consTree(e, emptyTree(), emptyTree());

	while (!empty(t)) {
		if (e <= root(t)){
			if (empty(left(t))){
				t->left = consTree(e, emptyTree(), emptyTree());
				t = left(t);
			}
			t = left(t);
		}
		else {
			if (empty(right(t))){
				t->right = consTree(e, emptyTree(), emptyTree());
				t = right(t);
			}
			t = right(t);
		}
	}

	return l;
}