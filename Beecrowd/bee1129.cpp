/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream>
using namespace std;

int main(){
    int n, i;
    int a[5];
    while(cin >> n, n != 0){
        while(n--){
            char ans = '*';
            bool first = true;
            for(i = 0; i < 5; i++){
                cin >> a[i];
                if(a[i] <= 127){
                    if(first){
                        first = false;
                        ans = 'A' + i;
                    }
                    else{
                        ans = '*';
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
