#include "list.h"

list2 cons2(element2 e, list2 l){
	list2 t;
	t = (list2)malloc(sizeof(item2));
	t->value = e;
	t->next = l;
	return t;
}

list2 insOrd2(element2 e, list2 l){
	element2 el = e;
	if (l==NULL){
		return cons2(el, l);
	}
	if (strcmp(l->value.str, el.str)<0){
		return cons2(el, l);
	}
	l->next = insOrd2(el, l->next);
	return l;
}


void main(){
	list l = emptylist();
	element e;

	//INPUT

	FILE *f = fopen("prova.txt", "rt");
	if (f == NULL){
		return;
	}

	while (fscanf(f, "%s %s %s %d",e.cognome,e.nome, e.str, &e.numero) != EOF){
		l = cons(e, l);
	}
	fclose(f);
	list2 l2 = NULL;
	while (l != NULL){
		element2 el;
		el.numero = head(l).numero;
		strcpy(el.str,head(l).str);
		l2 = insOrd2(el, l2);
		l = tail(l);

	}


}