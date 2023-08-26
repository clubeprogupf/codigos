/*
    author: Leonardo Deliyannis Constantin
*/

#include<iostream>
using namespace std;
#define LEN 112

int main(){
    string s;
    while(getline(cin, s)){
        int x = 0;
        for(int i = 0; i < (int)s.size(); i++){
            x += (s[i] - '0') % 3;
        }
        printf("%d\n", x%3);
    }
    return 0;
}
