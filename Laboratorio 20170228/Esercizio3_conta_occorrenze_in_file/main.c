#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	
	FILE *f = fopen("F.txt", "rt");
	if (f == NULL){
		fclose(f);
		return EXIT_FAILURE;
	}

	char *app = NULL;
	int tmp=0,inparola = 0,len=0, conta=0;

	while (1){
		tmp = fgetc(f);
		if (tmp == EOF){
			break;
		}

		if (inparola){
			if (tmp == ' '){
				inparola = 0;
				len = 0;
				if (strcmp(app, argv[1])==0){
					++conta;
				}
			}
			else{
				++len;
				app = realloc(app, len + 1);
				app[len - 1] = tmp;
				app[len] = 0;
			}
		}
		else{
			if (tmp != ' '){
				inparola = 1;
				++len;
				app = realloc(app, len+1);
				app[len - 1] = tmp;
				app[len] = 0;
			}
		}
	}

	if (inparola){		
			if (strcmp(app, argv[1]) == 0){
				++conta;
			}
		
	}
		
	printf("%d", len);

	fclose(f);
	return EXIT_SUCCESS;
}