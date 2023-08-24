/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream>
using namespace std;
#define MAX 11234

int main(){
    int a, c;
    int x[MAX], i;
    int cnt;
    while(cin >> a >> c, a != 0){
        cnt = 0;
        for(i = 0; i < c; i++){
            cin >> x[i];
            if(i > 0){
                if(x[i-1] > x[i]){
                    cnt += x[i-1] - x[i];
                }
            }
            else{
                cnt += a - x[i];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
