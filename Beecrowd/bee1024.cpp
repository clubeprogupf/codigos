/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream> // cin, cout, getline
#include<ctype.h> // isalpha
#include<algorithm> // swap
using namespace std;

int main(){
    int n, i;
    string s;
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin, s);
        int sz = (int)s.size();
        for(i = 0; i < sz; i++)
            if(isalpha(s[i]))
                s[i] += 3;
        for(i = 0; i < sz/2; i++)
            swap(s[i], s[sz-1-i]);
        for(i = sz/2; i < sz; i++)
            s[i] -= 1;
        cout << s << endl;
    }
    return 0;
}
