/*
 * author: Leonardo Deliyannis Constantin
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, d;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cin >> d;
        for(int i = 0; i < (int)s.size(); i++){
            s[i] -= d;
            if(s[i] < 'A')
                s[i] += 26;
        }
        cout << s << endl;
    } 
    return 0;
}
