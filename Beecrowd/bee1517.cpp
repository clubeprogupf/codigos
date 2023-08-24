/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXN 23
#define MAXT 2020

int N, M, K;
int a[MAXN][MAXN][MAXT];
int dp[MAXN][MAXN][MAXT];

const int dx[] = { -1, -1, -1,  0,  0,  +1, +1, +1 };
const int dy[] = { -1,  0, +1, -1, +1,  -1, +0, +1 };

bool isValid(int x, int y){
    return (1 <= x && x <= N && 1 <= y && y <= M);
}

int solve(int x, int y, int t){
    if(t > 2*K || !isValid(x, y))
        return 0;
    if(dp[x][y][t] != -1)
        return dp[x][y][t];
    int ans = solve(x, y, t+1);
    for(int p = 0; p < 8; p++){
        ans = max(ans, solve(x+dx[p], y+dy[p], t+1));
    }
    return dp[x][y][t] = ans + a[x][y][t];
}

int main(){
    int i, x, y, t;
    while(scanf("%d %d %d", &N, &M, &K), N){
        memset(dp, -1, sizeof(dp));
        memset(a, 0, sizeof(dp));
        for(i = 0; i < K; i++){
            scanf("%d %d %d", &x, &y, &t);
            a[x][y][t] = 1;
        }
        scanf("%d %d", &x, &y);
        printf("%d\n", solve(x, y, 0));
    }
    return 0;
}
