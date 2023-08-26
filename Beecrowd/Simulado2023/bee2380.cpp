/*
    author: Leonardo Deliyannis Constantin
*/

#include<iostream>
#include<vector>
using namespace std;

class UnionFind{
private: vector<int> p, rank;
public:
    UnionFind(int n){
        p.assign(n, 0); rank.assign(n, 0);
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
    }
    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) p[y] = x;
            else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main(){
    int n, k, b1, b2;
    char q;
    while(cin >> n >> k){
        UnionFind UF(n);
        while(k--){
            scanf(" %c %d %d", &q, &b1, &b2);
            b1--, b2--;
            if(q == 'F')
                UF.unionSet(b1, b2);
            else{
                if(UF.isSameSet(b1, b2))
                    cout << "S\n";
                else
                    cout << "N\n";
            }
        }
    }
    return 0;
}
