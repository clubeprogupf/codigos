/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define MAX 1123

typedef pair<int, string> is;

char ch[MAX];
int N;
set<string> myset;
map<string, bool> vis;

void bfs(int i){
    string s;
    s.push_back(ch[i]);
    vis[s] = true;
    queue<is> q;
    q.push({i, s});
    while(!q.empty()){
        int u = q.front().first;
        string t = q.front().second;
        myset.insert(t);
        q.pop();
        for(int k = 1; u+k < N; k++){
            int j = u+k;
            string w = t;
            w.push_back(ch[j]);
            if(!vis[w]){
                vis[w] = true;
                q.push({j, w});
            }
        }
    }
}

int main(){
    while(scanf("%s", ch) != EOF){
        N = strlen(ch);
        myset.clear();
        vis.clear();
        for(int i = 0; i < N; i++){
            bfs(i);
        }
        for(auto s : myset){
            printf("%s\n", s.c_str());
        }
        printf("\n");
    }
    return 0;
}
