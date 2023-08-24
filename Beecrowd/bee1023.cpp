/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<math.h>
#include<utility>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

typedef pair<int, int> ii;

bool cmp(const ii &a, const ii &b){
    return a.second < b.second;
}

int main(){
    int n, x, y;
    int t = 0;
    while(scanf("%d", &n), n != 0){
        t++;
        if(t > 1)
            printf("\n");
        map<int, int> mp;
        int people = 0, consumption = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            mp[y / x] += x;
            people += x;
            consumption += y;
        }
        double avg = (double) consumption / (double) people;
        avg = trunc(avg * 100.0);
        avg /= 100.0;

        vector<ii> v;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            v.push_back({it->second, it->first});
        }
        sort(v.begin(), v.end(), cmp);
        n = (int)v.size();

        printf("Cidade# %d:\n", t);
        for(int i = 0; i < n; i++){
            printf("%d-%d%c", v[i].first, v[i].second,
                (i < n-1 ? ' ' : '\n'));
        }
        printf("Consumo medio: %.2lf m3.\n", avg);
    }
    return 0;
}
