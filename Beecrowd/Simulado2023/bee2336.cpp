/*
    author: Leonardo Deliyannis Constantin
*/

#include<iostream>
#include<string.h>
using namespace std;
#define MAX 1123
#define P (ll(1e9)+7)

typedef long long ll;
ll memo[MAX];

ll expmod(ll x, ll n){
    if(n == 0) return 1;
    ll y = 1;
    while(n > 1){
        if(n&1){
            y *= x % P;
            y %= P;
        }
        x *= x % P;
        x %= P;
        n /= 2;
    }
    return ((x % P) * (y % P)) % P;
}

void buildMemo(){
    for(int i = 0; i < MAX; i++){
        memo[i] = expmod(26, i); }}

ll toInt(const string &s){
    ll ret = 0;
    int tam = (int)s.size();
    for(int i = tam-1; i >= 0; i--){
        ret += ((s[i] - 'A') * memo[tam-1-i]) % P;
        ret %= P;
    }
    return ret;
}

int main(){
    string s;
    buildMemo();
    while(cin >> s){
        cout << toInt(s) << endl;;
    }
    return 0;
}
