#include "list.h"

list insOrd(element e, list l){
	if (empty(l)) return cons(e, NULL);
	else if (isLess(e, head(l)) || isEqual(e, head(l))){
		return cons(e, l);
	}
	else return cons(head(l), insOrd(e, tail(l)));
}


void main(){
	list l = NULL;
	l = insOrd(10, l);
	l = insOrd(4, l);
	l = insOrd(1, l);
	l = insOrd(6, l);
	l = insOrd(5, l);
	l = insOrd(9, l);
	l = insOrd(11, l);
	showlist(l);
}