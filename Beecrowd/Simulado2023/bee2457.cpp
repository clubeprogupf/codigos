/*
    author: Leonardo Deliyannis Constantin
*/

#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<ctype.h> // isalpha()
using namespace std;

int main(){
    char c;
    string s;
    map<char, int> freq;
    set<char> myset;
    while(cin >> c){
        cin.ignore();
        getline(cin, s);
        s.push_back(' ');
        int cnt = 0;
        for(int i = 0; i < (int)s.size(); i++){
            if(isalpha(s[i]))
                myset.insert(s[i]);
            else if(!myset.empty()){
                cnt++;
                for(char x : myset)
                    freq[x-'a']++;
                myset.clear();
            }
        }
        double ans = 
            (double) freq[c-'a'] * 100.0 / (double) cnt;
        cout << fixed << setprecision(1) << ans << endl;
        freq.clear();
        myset.clear();
    }
    return 0;
}
