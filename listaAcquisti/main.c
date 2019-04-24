#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

list returnMax(list l){
	list lmax = emptylist(),ltmp=emptylist(),rootl=l;
	while (!empty(rootl)){
		float prezzo = head(rootl).Costo;
		while (!empty(l)){
			if (head(l).Costo == prezzo){
				ltmp=cons(head(l), ltmp);
			}
			l = tail(l);
		}
		if (lenght(ltmp) > lenght(lmax)){
			lmax = copy_list(ltmp);
		}
		ltmp = NULL;
		rootl = tail(rootl);
		l = rootl;
	}
	return lmax;
}

void jesusFunz(list l,list *ltmp, list *lmax){
	if (empty(l)){
		if (lenght(*ltmp) > lenght(*lmax)){			
			*lmax=copy_list(*ltmp);
		}
		*ltmp = NULL;
		return;
	}	
	while (!empty(l)){
		if (empty(*ltmp) || head(*ltmp).Costo == head(l).Costo){
			*ltmp = cons(head(l), *ltmp);
		}
		
		jesusFunz(tail(l), ltmp, lmax);

		l = tail(l);
	}
}

void main(){
	FILE *f = fopen("acquisti.dat", "rb");
	if (f == NULL){
		return;
	}
	list l = emptylist();
	element e;
	while (fscanf(f," %s %f",e.Nome,&e.Costo)!=EOF){
		l = cons(e, l);
	}
	list max = NULL,tmp=NULL;

	jesusFunz(l, &tmp, &max);
}
