/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 112
#define EPS 1e-9

typedef struct {
	char o[MAX];
	double p;
	int e;
} presente;

int cmp(const void *p1, const void *p2){
	presente a = *(presente*)p1;
	presente b = *(presente*)p2;
	if(a.e != b.e){
		return b.e - a.e;
	}
	if(fabs(a.p - b.p) > EPS){
		return (a.p < b.p) ? -1 : 1;
	}
	return strcmp(a.o, b.o);
}

int main(void){
	char nome[MAX];
	int Q, i;
	presente v[MAX];
	while(scanf("%s %d\n", nome, &Q) != EOF){
		for(i = 0; i < Q; i++){
			fgets(v[i].o, MAX, stdin);
			v[i].o[strlen(v[i].o) - 1] = '\0';
			scanf("%lf %d\n", &v[i].p, &v[i].e);
		}
		qsort(v, Q, sizeof(v[0]), &cmp);
		printf("Lista de %s\n", nome);
		for(i = 0; i < Q; i++){
			printf("%s - R$%.2lf\n", v[i].o, v[i].p);
		}
		printf("\n");
	}
	return 0;
}
