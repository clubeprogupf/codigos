/*
 * author: Leonardo Deliyannis Constantin
 */

#include <iostream>
#define MAX 112

using namespace std;
 
int main() {
    int n, m;
    int resp;
    int x;
    while(cin >> n >> m){
        resp = 0;
        for(int i = 0; i < n; i++){
            int scored = 0;
            for(int j = 0; j < m; j++){
                cin >> x;
                if(x > 0){
                    scored += 1;
                }
            }
            if(scored == m){
                resp += 1;
            }
        }
        cout << resp << endl;
    }
    return 0;
}
