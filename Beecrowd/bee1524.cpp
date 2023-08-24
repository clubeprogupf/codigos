/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<vector>
#include<utility> // pair<int, int>
#include<algorithm> // sort()
using namespace std;

typedef pair<int, int> ii;

bool distCmp(const ii &a, const ii &b){
    return a.first > b.first;
}

bool idxCmp(const ii &a, const ii &b){
    return a.second < b.second;
}

int main(void){
    int n, k, i;
    int sum, last, curr;
    while(scanf("%d %d", &n, &k) != EOF){
        vector<int> pos(n, 0);
        vector<ii> idx(n, ii({0, 0}));		
        for(i = 1; i < n; i++){
            scanf("%d", &pos[i]);
            idx[i] = {pos[i] - pos[i-1], i};
        }
        k -= 1;
        sort(idx.begin(), idx.end(), distCmp);
        sort(idx.begin(), idx.begin() + k, idxCmp);
        sum = 0;
        curr = 0;
        for(i = 0; i < k; i++){
            last = curr;
            curr = idx[i].second;
            sum += pos[curr-1] - pos[last];
        }
        sum += pos[n-1] - pos[curr];
        printf("%d\n", sum);
    }
    return 0;
}
