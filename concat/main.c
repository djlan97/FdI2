#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>
#include <string.h>

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

list join(list a, list b){
	if (empty(a) || empty(b)){
		return NULL;
	}
	int count=0;
	int max=0;
	element maxe;
	list roota = a,rootb=b;
	while (!empty(a)){
		char tmp[50];
		strcpy(tmp, head(a).str);
		while (!empty(b)){
			if (head(a).val == head(b).val){
				count++;
				strcat(a->value.str, head(b).str);
			}
			b = tail(b);
		}
		if (strcmp(head(a).str, tmp) == 0){
			roota = delete(head(a), roota);
		}
		else{
			if (count > max){
				max = count;
				maxe = copy(head(a));
			}			
		}
		count = 0;
		a = tail(a);
		b = rootb;
	}
	printElement(maxe);
	printf("\n");
	return roota;
}

/*list join(list a, list b){
	if (empty(a) || empty(b)){
		return emptylist();
	}
	list c = emptylist();
	list rootb = b;

	while (!empty(a)){
		int concat = 0;
		element e;
		char str[50];
		strcpy(str, head(a).str);
		while (!empty(b)){
			if (isEqual(head(a), head(b))){
				strcat(str, head(b).str);
				concat = 1;
			}
			b = tail(b);
		}
		if (concat){
			e.val = head(a).val;
			strcpy(e.str, str);
			c = insCoda(e, c);
		}
		b = rootb;
		a = tail(a);
	}

	return c;
}
*/
void main(){
	FILE *f = fopen("File 1.txt", "rt");
	if (f == NULL){
		return;
	}
	list a = emptylist();
	element e;
	while (fscanf(f, " %d, %s", &e.val, e.str)!=EOF){
		
		a = insCoda(e, a);
	}
	fclose(f);
	f = fopen("File 2.txt", "rt");
	if (f == NULL){
		return;
	}
	list b = emptylist();
	while (fscanf(f, " %d, %s", &e.val, e.str) != EOF){

		b = insCoda(e, b);
	}
	fclose(f);
	list c = emptylist();
	c = join(a, b);
	showlist(c);
}