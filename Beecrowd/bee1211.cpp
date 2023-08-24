/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 11234
#define TAM 212

int cmp(const void *p1, const void *p2){
	return strcmp((char*)p1, (char*)p2);
}

int main(void){
	int N, i, j, tam, cont;
	char v[MAX][TAM];
	while(scanf("%d\n", &N) != EOF){
		cont = 0;
		for(i = 0; i < N; i++){
			scanf("%s", v[i]);
		}
		tam = strlen(v[0]);
		qsort(v, N, sizeof(v[0]), &cmp);
		for(i = 1; i < N; i++){
			for(j = 0; j < tam; j++){
				if(v[i-1][j] == v[i][j])
                    cont++;
				else
                    break;
			}
		}
		printf("%d\n", cont);
	}
	return 0;
}
