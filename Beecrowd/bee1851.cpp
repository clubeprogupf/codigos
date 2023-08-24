/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream> // cin, cout
#include<utility> // pair<>
#include<queue> // priority_queue<>
using namespace std;
#define MAX 112345

typedef pair<double, int> di;
typedef unsigned long long ull;

int main(){
    int n = 0;
    int t[MAX], f[MAX];
    ull fine = 0;
    while(cin >> t[n] >> f[n]){
        n++;
    }
    priority_queue<di> pq;
    int i = 0;
    int day = 0;
    while(true){
        while(i < n && i <= day){
            double rate = (double)f[i] / (double)t[i];
            pq.push({rate, i});
            i++;
        }
        if(pq.empty()){
            if(i >= n) break;
            continue;
        }
        int j = pq.top().second;
        pq.pop();
        fine += (ull)f[j] * (ull)(day-j);
        day += t[j];
    }
    cout << fine << endl;
    return 0;
}
