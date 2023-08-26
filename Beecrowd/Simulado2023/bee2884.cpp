/*
    author: Leonardo Deliyannis Constantin
*/

#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
#define MAX 1123

typedef bitset<MAX> bs;

int main(){
    int n, m, l, x;
    bs lamps;
    ios_base::sync_with_stdio(false);
    while(cin >> n >> m){
        lamps.reset();
        cin >> l;
        while(l--){
            cin >> x;
            lamps[x-1] = true;
        }
        vector<bs> in(n, bs());
        for(int i = 0; i < n; i++){
            int k, y;
            cin >> k;
            while(k--){
                cin >> y;
                in[i][y-1] = 1;
            }
        }
        int i = 0;
        while(lamps.count() > 0 && i < n*n){
            lamps ^= in[i%n];
            i++;
        }
        printf("%d\n", lamps.count() ? -1 : i);
    }
    return 0;
}
