#include "list.h"


/*DEFINIZIONI*/

/*PRIMITIVE*/
list emptylist(){
	return NULL;
}

boolean empty(list l){
	return (l == NULL);
}

element head(list l){
	if (empty(l))abort();
	else return l->value;
}

list tail(list l){
	if (empty(l)) abort();
	else return l->next;
}

list cons(element e, list l){
	list t;
	t = (list)malloc(sizeof(item));
	t->value = copy(e);
	t->next = l;
	return t;
}

/*NON PRIMITIVE*/
void showlist(list l){
	while (!empty(l)){
		printElement(head(l));
		l = tail(l);
		if (!empty(l)) printf(" ");
	}
	printf("\n");
}

boolean member(element el, list l){
	while (!empty(l)){
		if (isEqual(el, head(l))) return true;
		else l = tail(l);
	}
	return false;
}

/*boolean member(element el, list l){
if (empty(l)) return 0;
else{
if (isEqual(el, head(l))) return 1;
else return member(el, tail(l));
}
}*/

int lenght(list l){
	int n = 0;
	while (!empty(l)){
		n++;
		l = tail(l);
	}
	return n;
}

/*int lenght(list l){
if (empty(l))return 0;
else return 1 + lenght(tail(l));
}*/

list append(list l1, list l2){
	if (empty(l1)) return l2;
	else return cons(head(l1), append(tail(l1), l2));
}

list copy_list(list l){
	if (empty(l)) return l;
	else return cons(head(l), copy_list(tail(l)));
}

list delete(element el, list l){
	if (empty(l)) return emptylist();
	else{
		if (isEqual(el, head(l))) return tail(l);
		else return cons(head(l), delete(el, tail(l)));
	}
}

void dealloc(list l){
	list temp;
	while (!empty(l)) {
		temp = l;
		l = tail(l);
		free(temp);
	}
}