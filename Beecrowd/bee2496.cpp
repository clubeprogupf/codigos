/*
 * author: Leonardo Deliyannis Constantin
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    string s;
    cin >> n;
    while(n--){
        cin >> m;
        cin >> s;
        int cnt = 0;
        string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i = 0; i < m; i++){
            if(s[i] != a[i])
                cnt++;
        }
        if(cnt <= 2)
            cout << "There are the chance.\n";
        else
            cout << "There aren't the chance.\n";
    }
    return 0;
}
