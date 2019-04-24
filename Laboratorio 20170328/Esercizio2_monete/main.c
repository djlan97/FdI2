#include <stdlib.h>
#include <stdio.h>
void conta_monete(int *t,int *c,int b, int n){
	
	for (int i = 0; i<n;++i){
		c[i] = b / t[i];
		b %= t[i];
	
	
	/*for (int i = 0; b > 0;){
				
		
		if (t[i] <= b){
			
			b -= t[i];
			
			c[i]++;
		}
		else{
			++i;
		}*/
	}
}


void main(){
	int budget = 125;
	int tagli[] = { 50, 20, 10, 5, 2, 1 };
	int conta[] = { 0, 0, 0, 0, 0, 0 };

	conta_monete(tagli, conta, budget, sizeof(tagli)/sizeof(tagli[0]));



	for (int i = 0; i < sizeof(tagli) / sizeof(tagli[0]); ++i){
		printf("%d da %d\n", conta[i], tagli[i]);
	}

	getchar();
}