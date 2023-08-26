/*
    author: Leonardo Deliyannis Constantin
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    string a[4];
    while(cin >> a[0]){
        int N = (int)a[0].size();
        for(int i = 1; i < 4; i++){
            cin >> a[i];
        }
        vector<int> m(N, 0);
        for(int j = 0; j < N; j++){
            for(int i = 0; i < 4; i++){
                m[j] *= 10;
                m[j] += a[i][j] - '0';
            }
        }
        const int F = m[0];
        const int L = m[N-1];
        string c;
        for(int j = 1; j < N-1; j++){
            c.push_back((F * m[j] + L) % 257);
        }
        cout << c << endl;
    }
    return 0;
}
