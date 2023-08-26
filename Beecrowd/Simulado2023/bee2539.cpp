/*
    author: Leonardo Deliyannis Constantin
*/

#include<iostream>
#include<vector>
using namespace std;
#define LSOne(S) (S & (-S))
#define MAX 112345

typedef long long ll;

class FenwickTree{
private:
    vector<int> ft;
public:
    FenwickTree(){}
    FenwickTree(int n){ ft.assign(n+1, 0); }
    ll rsq(int b){
        ll sum = 0;
        for(; b > 0; b -= LSOne(b)){
            sum += (ll) ft[b];
        }
        return sum;
    }
    ll rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0LL : rsq(a-1));
    }
    void adjust(int k, int v){
        for(; k < (int)ft.size(); k += LSOne(k)){
            ft[k] += v;
        }
    }
};

int main(){
    int n, v[MAX];
    // linha abaixo foi necessária para evitar TLE
    ios_base::sync_with_stdio(false);
    while(cin >> n){
        FenwickTree bit(n);
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        ll ans = 0;
        for(int i = n; i >= 1; i--){
            bit.adjust(v[i], 1);
            ans += (ll) bit.rsq(v[i] + 1, n);
        }
        cout << ans << endl;
    }
    return 0;
}
