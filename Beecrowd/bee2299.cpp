/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXC 1123
#define MAXF 52

int C, F;
int n[MAXF], d[MAXF];
int memo[MAXF][MAXC];

int pd(int i, int w){
    if(i <= 0 || w == 0) return 0;
    if(memo[i][w] != -1)
        return memo[i][w];
    if(w - n[i] < 0)
        return memo[i][w] = pd(i-1, w);
    return memo[i][w] =
        max(pd(i-1, w), pd(i-1, w-n[i]) + d[i]);
}

int main(){
    int t = 0;
    while(scanf("%d %d", &C, &F), C != 0){
        t += 1;
        for(int i = 1; i <= F; i++){
            scanf("%d %d", &n[i], &d[i]);
        }
        memset(memo, -1, sizeof(memo));
        int ans = pd(F, C);
        printf("Teste %d\n", t);
        printf("%d\n\n", ans);
    }
    return 0;
}
