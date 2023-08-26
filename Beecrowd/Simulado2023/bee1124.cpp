/*
    author: Leonardo Deliyannis Constantin
*/

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int l, c, r1, r2;
    while(cin >> l >> c >> r1 >> r2, l != 0){
        int sum = r1 + r2;
        int dl = l - sum;
        int dc = c - sum;
        int d = dl * dl + dc * dc;
        if(sum * sum <= d
        && 2 * r1 <= l && 2 * r1 <= c
        && 2 * r2 <= l && 2 * r2 <= c)
            cout << "S\n";
        else
            cout << "N\n";
    }
    return 0;
}
