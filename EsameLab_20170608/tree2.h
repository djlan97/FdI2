#if !defined TREE2_H
#define TREE2_H

#include "element2.h"

/*DEFINIZIONI*/
typedef struct treeElement2{
	element2 value;
	struct treeElement2 *left, *right;
}node2;

typedef node2* tree2;

/*DICHIARAZIONI*/

/*PRIMITIVE*/
extern boolean isEmptyTree2(tree2 t);
extern tree2 emptyTree2(void);
extern element2 root2(tree2 t);
extern tree2 left2(tree2 t);
extern tree2 right2(tree2 t);
extern tree2 consTree2(element2 e, tree2 l, tree2 r);

/*NON PRIMITIVE*/
extern void preOrder2(tree2 t);
extern void inOrder2(tree2 t);
extern void postOrder2(tree2 t);
extern tree2 insordTree2(element2 e, tree2 t);
extern boolean memberTree2(element2 e, tree2 t);
extern int height2(tree2 t);

/*BST*/
extern tree2 insertBinOrd2(element2 e, tree2 t);
extern boolean memberTree2Ord(element2 e, tree2 t);
extern tree2 deleteTree2(element2 e, tree2 t);

#endif/*TREE_H2*/