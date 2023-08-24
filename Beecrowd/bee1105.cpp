/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream>
#include<vector>
using namespace std;
#define MAX 21

int main(){
    int b, n, i;
    vector<int> r(MAX, 0);
    while(cin >> b >> n, b != 0){
        for(i = 1; i <= b; i++){
            cin >> r[i];
        }
        int d, c, v;
        while(n--){
            cin >> d >> c >> v;
            r[d] -= v;
            r[c] += v;
        }
        bool ans = true;
        for(i = 1; i <= b; i++){
            if(r[i] < 0){
                ans = false;
                break;
            }
        }
        cout << (ans ? 'S' : 'N') << endl;
    }
    return 0;
}
