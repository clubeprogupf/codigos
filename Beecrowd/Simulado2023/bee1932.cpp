/*
    author: Leonardo Deliyannis Constantin
*/

#include<iostream>
#include<algorithm> // max()
#include<string.h> // memset()
using namespace std;
#define MAXN 212345
#define INF 0x3f3f3f3f

int n, c;
int p[MAXN];
int dp[MAXN][2];
/*
int solve(int d, bool has){
    if(d == n)
        return 0;
    if(dp[d][has] != -1)
        return dp[d][has];
    int val = has ? p[d] : -(p[d] + c);
    return dp[d][has] = max(
        solve(d+1, has),
        solve(d+1, !has) + val);
}
*/
int solve(int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    dp[n][0] = dp[n][1] = 0;
    for(int d = n-1; d >= 0; d--){
        for(int has = 0; has <= 1; has++){
            int val = has ? p[d] : -(p[d] + c);
            dp[d][has] = max(
                dp[d+1][has], 
                dp[d+1][!has] + val);
        }
    }
    return dp[i][j];
}

int main(){
    while(cin >> n >> c){
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, false);
        cout << ans << endl;
    }
    return 0;
}
