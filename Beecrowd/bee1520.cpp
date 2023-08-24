/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<stdlib.h>
#define MAX 11234

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	int n, x, y, num;
	int v[MAX], qtd, i, j;
	int *pItem;
	int inic, fim;
	while(scanf("%d", &n) != EOF){
		qtd = 0;
		for(i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			for(j = x; j <= y; j++){
				v[qtd++] = j;
			}
		}
		qsort(v, qtd, sizeof(v[0]), &cmp);
		scanf("%d", &num);
		pItem = (int*) bsearch(&num, v, qtd, sizeof(v[0]), &cmp);
		if(pItem == NULL){
			printf("%d not found\n", num);
		}
		else{
			inic = fim = pItem - v;
			while(inic > 0 && v[inic-1] == num)
                inic--;
			while(fim < qtd && v[fim+1] == num)
                fim++;
			printf("%d found from %d to %d\n", num, inic, fim);
		}
	}
	return 0;
}
