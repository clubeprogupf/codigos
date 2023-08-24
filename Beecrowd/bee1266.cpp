/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream>
#include<vector>
using namespace std;
// #define MAX 5123

int main(){
    int n, i;
    while(cin >> n, n != 0){
        vector<int> x(n+1, 0);
        int first = -1;
        for(i = 0; i < n; i++){
            cin >> x[i];
            if(first == -1 && x[i] == 1){
                first = i;
            }
        };
        x[n] = x[0];
        int p = 0;
        for(i = 0; i <= n; i++){
            int j = (i+first)%n;
            if(x[j] == 0 && x[j+1] == 0){
                p++;
                i++;
            }
        }
        cout << p << endl;
    }
    return 0;
}
