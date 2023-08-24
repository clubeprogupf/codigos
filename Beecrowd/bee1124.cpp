/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int l, c, r1, r2;
    while(cin >> l >> c >> r1 >> r2, l != 0){
        int sum = r1 + r2;
        int dl = l - sum, dc = c - sum;
        int d = dl * dl + dc * dc;
        if()
            cout << "S\n";
        else
            cout << "N\n";
    }
    return 0;
}
