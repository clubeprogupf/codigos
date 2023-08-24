/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream>
#include<cctype>
using namespace std;

string reverse(const string &s){
    return string(s.rbegin(), s.rend());
}

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        string ans;
        for(char c : s){
            if(islower(c))
                ans.push_back(c);
        }
        ans = reverse(ans);
        cout << ans << endl;
    }
    return 0;
}
