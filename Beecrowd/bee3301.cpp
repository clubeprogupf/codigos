/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream>
using namespace std;

int main(){
    int h, z, l;
    while(cin >> h >> z >> l){
        if((z < h && h < l) || (l < h && h < z))
            cout << "huguinho\n";
        if((z < l && l < h) || (h < l && l < z))
            cout << "luisinho\n";
        if((h < z && z < l) || (l < z && z < h))
            cout << "zezinho\n";
    }
    return 0;
}
