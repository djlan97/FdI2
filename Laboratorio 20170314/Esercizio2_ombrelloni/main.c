#include <stdio.h>
void SubsetK(int n, int s, int v[], int *num, int count, int k){
	if (count == k){
		(*num)++;
		printf("%d) ",*num);

		for (int i = 0; i < n; ++i){
			printf("%d", v[i]);
		}

		/*for (int i = 0; i < n-s; ++i){
			printf("%d", 0);
		}*/

		printf("\n");

		return;
	}
	if (s == n) return;
	
	
	for (int i = 0; i < 2; ++i){
		if (i == 0){
			v[s] = i;
			SubsetK(n, s + 1, v, num, count, k);
			
		}
		else if (s == 0 || (v[s - 1] == 0 && s > 0)){
			v[s] = i;
			count++;
			SubsetK(n, s + 1, v, num, count, k);
			
		}
		v[s] = 0;
	}


	/*v[s] = 0;
	SubsetK(n, s + 1, v, num, count, k);
	
	if (s == 0 || (v[s - 1] == 0 && s > 0)){
		v[s] = 1;
		count++;
		SubsetK(n, s + 1, v, num, count, k);
		
	}
	v[s] = 0;
	*/

}

int main(void){

	int v[6], num=0;
	

	SubsetK(6, 0, v, &num, 0, 3);

	return 0;
}