/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXN 52
#define MAXW 112

int N, x[MAXN], y[MAXN];
int dp[MAXN][MAXW];

int knapsack(int n, int W){
    if(n == N || W == 0)
        return 0;
    if(dp[n][W] != -1) 
        return dp[n][W];
    return dp[n][W] = ((y[n] > W) ? 
        knapsack(n+1, W) :
        max(knapsack(n+1, W), 
            x[n] + knapsack(n+1, W-y[n])));
}

int main(){
    int T, K, R;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%d %d", x+i, y+i);
        }
        scanf("%d", &K);
        scanf("%d", &R);
        memset(dp, -1, sizeof(dp));
        if(knapsack(0, K) >= R)
            printf("Missao completada com sucesso\n");
        else printf("Falha na missao\n");
    }
    return 0;
}
