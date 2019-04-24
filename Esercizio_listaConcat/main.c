#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define boolean bool 
#define MAX 50

typedef struct elem{
	long val;
	char str[MAX];
	struct elem *next;
}elem;

typedef elem *list;

list emptylist(){
	return NULL;
}

boolean empty(list l){
	return (l == NULL);
}


list tail(list l){
	if (empty(l)) abort();
	else return l->next;
}

list insInCoda(char *s, long e, list l){
	list root = l;
	if (root == NULL){
		root = (list)malloc(sizeof(elem));
		root->next = NULL;
		strcpy(root->str, s);
		root->val = e;
	}
	else{
		while (tail(l) != NULL){
			l = tail(l);
		}
		list tmp = (list)malloc(sizeof(elem));
		tmp->next = emptylist();
		tmp->val = e;
		strcpy(tmp->str, s);
		l->next = tmp;
	}
	return root;
}

list cons(char*s,long n, list l){
	list t;
	t = (list)malloc(sizeof(elem));
	t->val = n;
	t->next = l;
	strcpy(t->str, s);
	return t;
}

list delete(long val, list l){
		list root = l;
		if (empty(l)) return NULL;
		if (l->val == val)
		{
			return l->next;
		}
		list back = l;
		l = l->next;
		while (!empty(l))
		{
			if (l->val == val)
			{
				back->next = l->next;
				break;
			}
			back = l;
		}
		return root;
	

	/*if (empty(l)){
		printf("\nLista vuota.");
		return l;
	}
	else{
		list ret = emptylist();
		while (!empty(l)){
			if (num!=l->val){
				ret = insInCoda(l->str,l->val, ret);
				l = tail(l);
			}
			else{
				ret->next = tail(l);
				break;
			}

		}
		return ret;
	}*/
}



/*list join(list a, list b){
	list roota = a, rootb = b;
	while (!empty(a)){
		char cmp[MAX];
		strcpy(cmp, a->str);
		b = rootb;
		while (!empty(b)){

			if (a->val == b->val){
				strcat(a->str, b->str);
			}
			b = tail(b);
		}
		if (strcmp(cmp, a->str) == 0){
			roota=delete(a->val, roota);
		}
		a = tail(a);
		
	}
	return roota;
}*/

list join(list a, list b,elem *lmax){
	//list Max_cat = emptylist();
	list roota = a, rootb = b;
	int max = 0, count = 0;
	while (!empty(a)){
		char cmp[MAX];
		strcpy(cmp, a->str);
		b = rootb;
		while (!empty(b)){

			if (a->val == b->val){
				strcat(a->str, b->str);
				++count;
			}
			b = tail(b);
		}
		if (count > max){
			max = count;
			lmax->val = a->val;
			strcpy(lmax->str, a->str);
		}
		if (strcmp(cmp, a->str) == 0){
			roota = delete(a->val, roota);
		}
		a = tail(a);
		count = 0;
	}


	//printf("%d %s", Max_cat->val, Max_cat->str);

	return roota;
}

void main(){
	FILE *f = fopen("File1.txt", "rt");
	if (f == NULL){
		fclose(f);
		return;
	}

	FILE *g = fopen("File2.txt", "rt");
	if (g == NULL){
		fclose(g);
		return;
	}
	list l1 = NULL;
	char tmp[50];
	long num;
	while (fscanf(f, " %d %*[,\"]  %[^\"] %*[\"]", &num,tmp) != EOF){
		l1 = insInCoda(tmp, num, l1);
	}
	list l2 = emptylist();
	while (fscanf(g, " %d %*[,\"]  %[^\"] %*[\"]", &num, tmp) != EOF){
		l2 = insInCoda(tmp, num, l2);
	}
	elem max;
	list l3 = join(l1, l2,&max);
	printf("%d %s", max.val, max.str);
}