/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1123
#define LEN 112

typedef struct _rena{
	char nome[LEN];
	int peso, idade;
	double altura;
} rena;

int cmp(const void *p1, const void *p2){
	rena a = *(rena*)p1;
	rena b = *(rena*)p2;
	if(a.peso != b.peso){
		return (a.peso > b.peso) ? -1 : 1;
	}
	if(a.idade != b.idade){
		return (a.idade < b.idade) ? -1 : 1;
	}
	if(a.altura != b.altura){
		return (a.altura < b.altura) ? -1 : 1;
	}
	return strcmp(a.nome, b.nome);
}

int main(void){
	int t, n, m;
	int c, i;
	rena v[MAX];
	scanf("%d", &t);
	for(c = 1; c <= t; c++){
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++){
			getchar();
			scanf("%s %d %d %lf", v[i].nome, 
                &v[i].peso, &v[i].idade, &v[i].altura);
		}
		qsort(v, n, sizeof(v[0]), &cmp);
		printf("CENARIO {%d}\n", c);
		for(i = 0; i < m; i++){
			printf("%d - %s\n", i+1, v[i].nome);
		}
	}
	return 0;
}
