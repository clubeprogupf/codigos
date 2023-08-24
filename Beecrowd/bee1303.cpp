/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 112
#define TOLERANCIA 1e-9 /* 10^(-9) == 0.000000001 */
/* #define DEBUG */

typedef struct {
	int inscricao;
	int vitorias;
	int derrotas;
	int pontosMarcados;
	int pontosSofridos;
	int placar;
	double cestaAverage;
} equipe;

void inicializa(equipe lista[], int equipes){
	int i;
	for(i = 0; i < equipes; i++){
		lista[i].inscricao = i+1;
		lista[i].vitorias = 0;
		lista[i].derrotas = 0;
		lista[i].pontosMarcados = 0;
		lista[i].pontosSofridos = 0;
		lista[i].placar = 0;
		lista[i].cestaAverage = 0.0;
	}
}

void calculaCestaAverage(equipe lista[], int equipes){
	int i;
	for(i = 0; i < equipes; i++){
		if(lista[i].pontosSofridos == 0){
			lista[i].cestaAverage = (double) lista[i].pontosMarcados;
		}
		else{ 
			lista[i].cestaAverage = (double) lista[i].pontosMarcados / 
				(double) lista[i].pontosSofridos;
		}
	}
}

int comparaEquipes(const void *p1, const void *p2){
	equipe a = *(equipe*)p1;
	equipe b = *(equipe*)p2;
	if(a.placar != b.placar){
		return b.placar - a.placar;
	}
	/* correção de erros de precisão na comparação 
	 * entre números com casas após a vírgula */
	if(fabs(a.cestaAverage - b.cestaAverage) > TOLERANCIA){
		if(a.cestaAverage > b.cestaAverage) return -1;
		else if(a.cestaAverage < b.cestaAverage) return 1;
		else return 0;
	}
	if(a.pontosMarcados != b.pontosMarcados){
		return b.pontosMarcados - a.pontosMarcados;
	}
	return a.inscricao - b.inscricao;
}

#ifdef DEBUG
void imprimeLista(equipe lista[], int equipes){
	int i;
	for(i = 0; i < equipes; i++){
		printf("Equipe %d:\n", lista[i].inscricao);
		printf("Vitorias: %d\n", lista[i].vitorias);
		printf("Derrotas: %d\n", lista[i].vitorias);
		printf(": %d\n", lista[i].vitorias);
	}
}
#endif

int main(void){
	int N, i, partidas, instancia;
	int time1, pontos1, time2, pontos2;
	equipe lista[MAX];
	instancia = 0;
	while(scanf("%d", &N), N != 0){
		inicializa(lista, N);
		instancia++;
		if(instancia > 1){
			printf("\n");
		}
		
		partidas = N * (N-1) / 2;
		while(partidas--){
			scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);
			time1 = time1 - 1;
			time2 = time2 - 1;
			lista[time1].pontosMarcados += pontos1;
			lista[time2].pontosMarcados += pontos2;
			lista[time1].pontosSofridos += pontos2;
			lista[time2].pontosSofridos += pontos1;
			if(pontos1 > pontos2){
				lista[time1].vitorias += 1;
				lista[time2].derrotas += 1;
				lista[time1].placar += 2; 
				lista[time2].placar += 1; 
			}
			else{
				lista[time2].vitorias += 1;
				lista[time1].derrotas += 1;
				lista[time2].placar += 2;
				lista[time1].placar += 1;
			}
		}
		calculaCestaAverage(lista, N);
		qsort(lista, N, sizeof(lista[0]), &comparaEquipes);
				
		printf("Instancia %d\n", instancia);
		for(i = 0; i < N; i++){
			printf("%d", lista[i].inscricao);
			if(i == N-1) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
