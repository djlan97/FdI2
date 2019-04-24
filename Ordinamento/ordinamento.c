#include "ordinamento.h"
#define N 20
/*NAIVE SORT o SELECTION SORT*/

void naiveSort(int v[], int dim){
	int p;
	while (dim > 1){
		p = trovaPosMax(v, dim);
		if (p < dim - 1){
			scambia(&v[p], &v[dim - 1]);
		}
		dim--;
	}
}

/*BUBBLE SORT*/

void bubbleSort(int v[], int dim){
	int i;
	bool ordinato = false;
	while (dim > 1 && !ordinato){
		ordinato = true;	/* ipotesi: è ordinato */
		for (i = 0; i < dim - 1; i++){
			if (v[i]>v[i + 1]){
				scambia(&v[i], &v[i + 1]);
				ordinato = false;
			}
		}
		dim--;
	}
}

/*INSERT SORT*/

void insertSort(int v[], int dim){
	int i;
	for (i = 1; i < dim; i++){
		insMinore(v, i);
	}
}

void insMinore(int v[], int lastpos){
	int i, x = v[lastpos];
	for (i = lastpos - 1; i >= 0 && x < v[i]; i--){
		v[i + 1] = v[i];	/* crea lo spazio */
	}
	v[i + 1] = x;
}

/*QUICK SORT*/

void quickSort(int v[], int first, int last){
	int i, j, pivot;
	if (first < last){
		i = first;
		j = last;
		pivot = v[(first + last) / 2];
		do{
			while (v[i] < pivot){
				i++;
			}
			while (v[j]>pivot){
				j--;
			}
			if (i <= j){
				scambia(&v[i], &v[j]);
			}
			i++;
			j--;
		} while (i <= j);
		quickSort(v, first, j);
		quickSort(v, i, last);
	}
}

/*MERGE SORT*/

void mergeSort(int v[], int first, int last){
	int mid;
	if (first < last){
		mid = (last + first) / 2;
		mergeSort(v, first, mid);
		mergeSort(v, mid + 1, last);
		merge(v, first, mid + 1, last);
	}
}

void merge(int v[], int i1, int i2, int last){
	int vout[N];	/* vettore temporaneo */
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= last){
		if (v[i] < v[j]){
			vout[k] = v[i++];
		}
		else{
			vout[k] = v[j++];
		}
		k++;
	}
	while (i <= i2 - 1){
		vout[k] = v[i++];
		k++;
	}
	while (j <= last){
		vout[k] = v[j++];
		k++;
	}
	for (i = i1; i < last; i++){
		v[i] = vout[i];
	}
}


/*FUNZIONI DI SUPPORTO*/

void scambia(int *v1, int *v2){
	int tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

int trovaPosMax(int v[],int n){
	int i, p = 0;	/* ipotesi max = v[0] */
	for (i = 1; i < n; i++){
		if (v[p] < v[i]){
			p = i;
		}
	}
	return p;
}