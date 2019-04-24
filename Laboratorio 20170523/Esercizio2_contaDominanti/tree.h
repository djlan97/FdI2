#if !defined TREE_H
#define TREE_H

#include "element.h"

/*DEFINIZIONI*/
typedef struct treeElement{
	element value;
	struct treeElement *left, *right;
}node;

typedef node* tree;

/*DICHIARAZIONI*/

/*PRIMITIVE*/
extern boolean empty(tree t);
extern tree emptyTree(void);
extern element root(tree t);
extern tree left(tree t);
extern tree right(tree t);
extern tree consTree(element e, tree l, tree r);

/*NON PRIMITIVE*/
extern void preOrder(tree t);
extern void inOrder(tree t);
extern void postOrder(tree t);
extern tree insordTree(element e, tree t);
extern boolean memberTree(element e, tree t);
extern boolean memberOrdTree(element e, tree t);

/*BST*/
extern tree insertBinOrd(element e, tree t);

#endif/*TREE_H*/