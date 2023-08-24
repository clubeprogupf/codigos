/*
 * author: Leonardo Deliyannis Constantin
 */

#include<bits/stdc++.h>
using namespace std;
#define MAX 512

typedef pair<int, int> ii;

int n, m;
char g[MAX][MAX];
// bool vis[MAX][MAX];

int di[] = {-1,  0, 0, 1};
int dj[] = { 0, -1, 1, 0};

void floodfill(int si, int sj){
    /*
    for(int i = 0; i < n; i++){
        memset(vis[i], 0, sizeof(vis[i]));
    }
    vis[si][sj] = true;
    */
    queue<ii> q;
    q.push({si, sj});
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(i == n)
            continue;
        if(g[i+1][j] == '.'){
            g[i+1][j] = 'o';
            q.push({i+1, j});
        }
        else if(g[i+1][j] == '#'){
            if(0 < j && g[i][j-1] == '.'){
                g[i][j-1] = 'o';
                q.push({i, j-1});
            }
            if(j < m-1 && g[i][j+1] == '.'){
                g[i][j+1] = 'o';
                q.push({i, j+1});
            }
        }
    }
}

int main(){
    int i, j, si, sj;
    while(scanf("%d %d", &n, &m) != EOF){
        for(i = 0; i < n; i++){
            scanf(" %s", g[i]);
            // fgets(g[i], MAX, stdin);
            if(i == 0){
                for(j = 0; j < m; j++){
                    if(g[i][j] == 'o'){
                        si = i;
                        sj = j;
                        break;
                    }
                }
            }
        }
        floodfill(si, sj);
        for(i = 0; i < n; i++){
            printf("%s\n", g[i]);
        }
    }
    return 0;
}
