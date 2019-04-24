#include <stdlib.h>
#include <math.h>

int min_vect(int *v, int n){
	if (n == 1){
		return v[0];
	}
	else{
		return min(v[0], min_vect(v + 1, n - 1));
	}
}


int main(void){
	
	int v[] = { 1, 2, 4, 3, 21, 6, 7, 99, 104 };
	int min = min_vect(v, sizeof(v) / sizeof(v[0]));


	return EXIT_SUCCESS;
}