#include "list.h"

void maxinteressi(list l){
	int max = 0;
	list lmax = emptylist();
	while (!empty(l)){
		if (l->value.interessi > max){
			max = l->value.interessi;
			lmax = l;
		}
		l = tail(l);
	}
	printElement(lmax->value);
}

void visualizzaCoppie(list l){
	list root = l;
	while (!empty(root)){
		list v = emptylist();
		v = cons(root->value, v);
		while (!empty(tail(l))){
			l = tail(l);
			if (l->value.interessi == v->value.interessi){
				v = cons(l->value, v);
				showlist(v);
			}
		}
		root = tail(root);
		l = root;
	}
}

void main(){
	FILE *f = fopen("utenti.txt", "rt");
	if (f == NULL){
		fclose(f);
		return;
	}
	element e;
	list l = emptylist();
	while (fscanf(f, " %[^:]%*[:]", e.nome) >0){
		int count = 0;
		while (fscanf(f, " %*[^\n,]") !=EOF){
			count++;
			if (fgetc(f) != ',' || fgetc(f) == EOF){
				break;
			}
		}
		e.interessi = count;
		l = cons(e, l);
	}

	maxinteressi(l);
	visualizzaCoppie(l);
}