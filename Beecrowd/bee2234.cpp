/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream>
#include<iomanip> // fixed, setprecision()
using namespace std;

int main(){
    int h, p;
    double ans;
    while(cin >> h >> p){
        ans = (double)h / (double)p;
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
