#include "list.h"
#include "element.h"


//FUNZIONI

void scambia(element *e1, element *e2){
	element tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

boolean isMore(element e1, element e2){
	return (strcmp(e1.nome, e2.nome) > 0);
}

list newAddress(element e, list l){
	list root = l;
	if (empty(root)){
		root = cons(e, root);
	}
	else{
		while (tail(l) != emptylist()){
			l = tail(l);
		}
		list tmp = (list)malloc(sizeof(item));
		tmp->next = emptylist();
		tmp->value = copy(e);
		l->next = tmp;
	}
	return root;
}


void showAddress(list l){
	if (empty(l)){
		printf("\nLista vuota.");
	}
	printf("\nNOME\tINDIRIZZO");
	while (!empty(l)){
		printElement(head(l));
		l = tail(l);
		if (!empty(l)) printf("\n");
	}
	printf("\n");
}

list delAddress(element e, list l){
	if (empty(l)){
		printf("\nLista vuota.");
		return l;
	}
	else{
		list ret = emptylist();
		while (!empty(l)){
			if (!isEqual(e, head(l))){
				ret = newAddress(head(l), ret);
				l = tail(l);
			}
			else{
				ret->next = tail(l);
				break;
			}

		}
		return ret;
	}
}

void findElement(element e, list l){
	boolean trovato = false;
	while (!empty(l)&&!trovato){
		if (isEqual(head(l), e)){
			e = head(l);
			trovato = true;
		}
		l = tail(l);
	}
	if (trovato){
		printElement(e);
	}else{
		printf("\nElemento non presente!");
	}
}

list ordina(list l){
	if (empty(l)){
		printf("\nLista vuota.");
		return emptylist();
	}
	list root = l;
	bool ordinato = false;
	while (!ordinato){
		ordinato = true;	/* ipotesi: è ordinato */
		while (!empty(tail(l))){
			list succ = tail(l);
			if (!isLess(l->value,succ->value)){
				scambia(&(l->value), &(succ->value));
				ordinato = false;
			}
			l = tail(l);
		}
		l = root;
	}
	return root;
}


//MAIN
void main(){
	list rubrica = emptylist();
	int c = 0;

	do{
		printf("\nLe funzioni disponibili sono:\n1. Inserisci un nuovo indirizzo.\n2. Stampa tutti gli indirizzi.\n3. Cerca un indirizzo.\n4. Elimina un indirizzo.\n5. Ordina indirizzi.\n0. Esci\nCosa devo fare?\t");
		fscanf(stdin, " %d", &c);
		fflush(stdin);

		switch (c){
		case 0:
			break;
		case 1:
			printf("\n***INSERISCI UN CONTATTO***");
			element add = getElement();
			rubrica = newAddress(add, rubrica);
			break;
		case 2:
			printf("\n***CONTATTI IN RUBRICA***");
			showAddress(rubrica);
			break;
		case 3:
			printf("\n***CERCA IN RUBRICA***");
			printf("\nInserisci nome:\t");
			element name;
			scanf(" %s", &name.nome);
			findElement(name, rubrica);
			break;
		case 4:
			printf("\n***ELIMINA UN CONTATTO***");
			element del=getElement();
			
			rubrica = delAddress(del, rubrica);
			break;
		case 5:
			//BUBBLE SORT
			rubrica = ordina(rubrica);
			break;
		default:
			printf("\n***Valore non valido riprovare!***\n");
			break;
		}
	} while (c != 0);
}