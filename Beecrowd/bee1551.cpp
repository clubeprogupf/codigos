/*
 * author: Leonardo Deliyannis Constantin
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        vector<int> cnt(26, 0);
        for(int i = 0; s[i] != '\0'; i++){
            if(isalpha(s[i]))
                cnt[s[i] - 'a']++;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(cnt[i] > 0)
                ans++;
        }
        cout << "frase ";
        if(ans < 13)
            cout << "mal elaborada\n";
        else if(13 <= ans && ans < 26)
            cout << "quase completa\n";
        else
            cout << "completa\n";
    }    
    return 0;
}
