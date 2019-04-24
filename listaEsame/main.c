#include "list.h"
#include <stdio.h>

listInt consInt(int e, listInt l){
	listInt t;
	t = (listInt)malloc(sizeof(item2));
	t->value = e;
	t->next = l;
	return t;
}

listInt insOrd(int e, listInt l){
	if (l==NULL){
		return consInt(e, l);
	}
	if (e < l->value){
		return consInt(e, l);
	}
	l->next = insOrd(e, l->next);
	return l;
}

void showlistInt(listInt l){
	printf("[");
	while (l!=NULL){
		printf("%d", l->value);
		l = l->next;
		if (l!=NULL) printf(" -> ");
	}
	printf("]\n");
}



listInt insCoda(int e, listInt l){
	listInt root = l;
	if (l==NULL){
		l = consInt(e, l);
		return l;
	}
	while (l->next!=NULL){
		l = l->next;
	}
	listInt t = (listInt)malloc(sizeof(item2));
	t->value = e;
	t->next = NULL;
	l->next = t;
	return root;
}

listInt funz(list l1, list l2){
	listInt l3 = NULL;
	int i = 1;
	while (l1 != NULL && l2 != NULL){
		if (i % 2 == 0){
			l3 = insCoda(head(l1).id, l3);
			l1 = l1->next;
		}
		else{
			l3 = insCoda(head(l2).id, l3);
			l2 = l2->next;
		}
		
		i++;
	}

	if (l2 != NULL || l1 != NULL){
		list tmp = NULL;
		if(l1!=NULL){
			if (i % 2 == 0){
				l3 = insCoda(head(l1).id, l3);
				l1 = l1->next;
			}
			tmp = l1;
		}
		else{
			if (i % 2 != 0){
				l3 = insCoda(head(l2).id, l3);
				l2 = l2->next;
			}
			tmp = l2;
		}
		while (tmp != NULL){
			if (head(tmp).eta % 2 == 0){
				l3 = insCoda(head(tmp).eta*head(tmp).id, l3);
			}
			else{
				l3 = insCoda(head(tmp).id-head(tmp).eta, l3);
			}

			tmp = tmp->next;
		}
	}
	return l3;
}

void main(){
	FILE *f = fopen("file1.txt", "rt");
	if (f == NULL){
		return;
	}
	list l1=NULL,l2=NULL;
	element e;
	while (fscanf(f, " %s %s %d %d", e.cognome, e.nome, &e.eta, &e.id)!=EOF){
		l1 = cons(e, l1);
	}
	showlist(l1);
	fclose(f);

	f = fopen("file2.txt", "rt");
	if (f == NULL){
		return;
	}
	
	while (fscanf(f, " %s %s %d %d", e.cognome, e.nome, &e.eta, &e.id) != EOF){
		l2 = cons(e, l2);
	}
	showlist(l2);
	fclose(f);

	listInt l3 = funz(l1,l2);
	
	
	showlistInt(l3);
	listInt l4 = NULL,tmp=l3,l5=NULL;

	while (tmp != NULL){
		l4 = insOrd(tmp->value, l4);
		tmp = tmp->next;
	}
	showlistInt(l4);
	tmp = l3;
	while (tmp != NULL){
		l5 = insCoda(tmp->value - l4->value, l5);
		tmp = tmp->next;
		l4 = l4->next;
	}
	showlistInt(l5);

}