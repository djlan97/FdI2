#if !defined LIST_H
#define LIST_H
#include "element.h"

/*DEFINIZIONI*/
typedef struct list_element{
	element value;
	struct list_element *next;
}item;

typedef item* list;

/*DICHIARAZIONI*/

/*PRIMITIVE*/
extern list emptylist();
extern boolean empty(list l);
extern element head(list l);
list tail(list);
list cons(element e, list l);

/*NON PRIMITIVE*/
extern void showlist(list l);
extern boolean member(element el, list l);
extern int lenght(list l);
extern list append(list l1, list l2);
extern list copy_list(list l);

#endif/*LIST_H*/