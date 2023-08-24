/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream>
using namespace std;

void trimLeadingZeros(string &s){
    int i, n;
    n = (int)s.size();
    for(i = 0; s[i] == '0' && i < n-1; i++);
    s = s.substr(i, n-i);
}

void review(char c, string &s){
    string aux;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] != c)
            aux.push_back(s[i]);
    }
    if(aux.empty()){
        aux.push_back('0');
    }
    trimLeadingZeros(aux);
    s = aux;
}

int main(){
    char c;
    string n;
    while(cin >> c >> n, c != '0'){
        review(c, n);
        cout << n << endl;
    }
    return 0;
}
