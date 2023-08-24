/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream>
// #include<algorithm>
using namespace std;
#define MAX 61

int min(int a, int b){
    return (a < b) ? a : b;
}

int main(){
    int n, m, i;
    int e[MAX], d[MAX];
    char l;
    while(cin >> n){
        for(i = 30; i <= 60; i++){
            e[i] = 0;
            d[i] = 0;
        }
        while(n--){
            cin >> m >> l;
            if(l == 'E')
                e[m]++;
            if(l == 'D')
                d[m]++;
        }
        int p = 0;
        for(i = 30; i <= 60; i++){
            p += min(e[i], d[i]);
        }
        cout << p << endl;
    }
    return 0;
}
