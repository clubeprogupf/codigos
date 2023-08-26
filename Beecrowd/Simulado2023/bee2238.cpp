/*
    author: Leonardo Deliyannis Constantin
*/

#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f

set<int> dividers(int c){
    set<int> ans;
    for(int i = 1; i*i <= c; i++){
        if(c%i == 0){
            ans.insert(i);
            ans.insert(c/i);
        }
    }
    return ans;
}

int main(){
    int a, b, c, d;
    while(cin >> a >> b >> c >> d){
        set<int> s = dividers(c);
        int ans = INF;
        for(int n : s){
            if(n%a == 0 && n%b != 0 && d%n != 0){
                ans = n;
                break;
            }
        }
        if(ans != INF)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
