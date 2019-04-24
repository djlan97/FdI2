#include "tree.h"

/*DEFINIZIONI*/

/*PRIMITIVE*/
boolean isEmptyTree(tree t){
	return (t == NULL);
}

tree emptyTree(void){
	return NULL;
}

element root(tree t){
	if (isEmptyTree(t)) abort();
	else return t->value;
}

tree left(tree t){
	if (isEmptyTree(t)) return NULL;
	else return t->left;
}

tree right(tree t){
	if (isEmptyTree(t)) return NULL;
	else return t->right;
}

tree consTree(element e, tree l, tree r){
	tree t = (node*)malloc(sizeof(node));
	t->value = copy(e);
	t->left = l;
	t->right = r;
	return t;
}

/*NON PRIMITIVE*/
void preOrder(tree t){
	if (!isEmptyTree(t)){
		printf("\t");
		printElement(root(t));
		preOrder(left(t));
		preOrder(right(t));
	}
}

void inOrder(tree t){
	if (!isEmptyTree(t)){
		inOrder(left(t));
		printf("\t");
		printElement(root(t));
		inOrder(right(t));
	}
}

void postOrder(tree t){
	if (!isEmptyTree(t)){
		postOrder(left(t));
		postOrder(right(t));
		printf("\t");
		printElement(root(t));
	}
}

boolean memberTree(element e, tree t){
	if (isEmptyTree(t)) return false;
	else if (isEqual(e, root(t))) return true;
	else return (memberTree(e, left(t)) || memberTree(e, right(t)));
}

int height(tree t){
	if (isEmptyTree(t)) return 0;
	else{
		int hl = height(left(t)), hr=height(right(t));
		return 1 + (hl > hr ? hl : hr);
	}
}

/*BST*/

tree insertBinOrd(element e, tree t){

	tree l = t;

	if (isEmptyTree(t))
		return consTree(e, emptyTree(), emptyTree());

	while (!isEmptyTree(t)) {
		if (!isLess(root(t), e)){
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

boolean memberTreeOrd(element e, tree t){
	if (isEmptyTree(t)) return false;
	else 
	if (isEqual(e, root(t))) return true;
	else
	if (isLess(e, root(t))) return memberTreeOrd(e, left(t));
	else return memberTreeOrd(e, right(t));

}

tree deleteTree(element e, tree t){
	tree pl = emptyTree(), pr = emptyTree(), next = emptyTree(), l = t;

	/* CERCA IL NODO NELL'ALBERO */

	while (!isEmptyTree(t) && root(t) != e){
		if (e < root(t)){
			pl = t;
			pr = emptyTree();
			t = left(t);
		}
		else{
			pl = emptyTree();
			pr = t;
			t = right(t);
		}
	}

	/* Se t punta a NULL l'elemento non è presente nell'albero */
	if (isEmptyTree(t)) return l;

	/* Se è una foglia */
	if (isEmptyTree(left(t)) && isEmptyTree(right(t))){

		/* Se è la root ritorna un albero vuoto */

		if (t == l) return emptyTree();

		if (!isEmptyTree(pl)){
			pl->left = emptyTree();
		}
		else{
			pr->right = emptyTree();
		}

	}

	if (isEmptyTree(left(t)) && !isEmptyTree(right(t))){

		/* Se è la root ritorno il figlio */
		if (t == l) return right(t);
		next = right(t);
	}
	else{
		if (!isEmptyTree(left(t)) && isEmptyTree(right(t))){

			/* Se è la root ritorno il figlio */
			if (t == l) return left(t);
			next = left(t);
		}
	}

	if (!isEmptyTree(left(t)) && !isEmptyTree(right(t))){
		pr = t;
		pl = emptyTree();
		next = right(t);
		if (!isEmptyTree(next)){
			while (!isEmptyTree(left(next))){
				pr = emptyTree();
				pl = next;
				next = left(next);
			}
			t->value = root(next);
			if (!isEmptyTree(right(next))){
				next = right(next);
			}
			else{
				next = emptyTree();
			}
		}
	}


	if (!isEmptyTree(pl)) pl->left = next;
	else pr->right = next;
	return l;
}