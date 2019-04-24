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
	printf("[");
	while (!empty(l)){
		printElement(head(l));
		l = tail(l);
		if (!empty(l)) printf(", ");
	}
	printf("]\n");
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

void scambia(element *e1, element *e2){
	element tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}


list ordinaLista(list l){
	if (empty(l)){
		printf("LISTA VUOTA!");
		return emptylist();
	}
	if (empty(tail(l))){
		return l;
	}
	list root = l;
	bool ordinato = false;
	while (!ordinato){
		ordinato = true;	/* ipotesi: è ordinato */
		while (!empty(tail(l))){
			list succ = tail(l);
			if (!isLess(l->value, succ->value)){
				scambia(&(l->value), &(succ->value));
				ordinato = false;
			}
			l = tail(l);
		}
		l = root;
	}
	return root;
}

list insCoda(element e, list l){
	list root = l;
	if (empty(l)){
		l = cons(e, l);
		return l;
	}
	while (!empty(tail(l))){
		l = tail(l);
	}
	list t = (list)malloc(sizeof(item));
	t->value = copy(e);
	t->next = emptylist();
	l->next = t;
	return root;
}

void findAndPrintEl(element e, list l){
	if (empty(l)){
		printf("LISTA VUOTA!\n");
		return;
	}
	while (!empty(l)){

		if (isEqual(e, head(l))){
			printElement(head(l));
			return;
		}
		l = tail(l);
	}
	printf("ELEMENTO NON PRESENTE!\n");

}

list insOrd(element e, list l){
	if (empty(l)){
		return cons(e, l);
	}
	if (isLess(head(l),e)){
		return cons(e, l);
	}
	l->next = insOrd(e, tail(l));
	return l;
}


element findMax(list l){
	element max = 0;

	while (!empty(l)){
		if (isLess(max,head(l))){
			max = head(l);
		}
		l = tail(l);
	}

	return max;
}

list intersect(list l1, list l2){
	list l3 = emptylist();
	while (!empty(l1) && !empty(l2)){
		if (member(head(l1), l2)){
			l3 = cons(head(l1), l3);
		}
		l1 = tail(l1);
	}

	return l3;
}

list intersect_Norpt(list l1, list l2){
	list l3 = emptylist();
	while (!empty(l1) && !empty(l2)){
		if (member(head(l1), l2) && !member(head(l1), l3)){
			l3 = cons(head(l1), l3);
		}
		l1 = tail(l1);
	}

	return l3;
}

list difference(list l1, list l2){
	list l3 = emptylist();
	while (!empty(l1) && !empty(l2)){
		if (!member(head(l1), l2)){
			l3 = cons(head(l1), l3);
		}
		l1 = tail(l1);
	}
	return l3;
}

list difference_Norpt(list l1, list l2){
	list l3 = emptylist();
	while (!empty(l1) && !empty(l2)){
		if (!member(head(l1), l2) && !member(head(l1), l3)){
			l3 = cons(head(l1), l3);
		}
		l1 = tail(l1);
	}
	return l3;
}