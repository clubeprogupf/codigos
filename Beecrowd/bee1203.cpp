/*
 * author: Leonardo Deliyannis Constantin
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int r, k, a, b;
    while (cin >> r >> k) {
        vector<int> vet(r, 0);
        vector<bool> ok(k+1, false);
        for(int i = 0; i < k; i++) {
            cin >> a >> b;
            vet[a-1] += 1;
            vet[b-1] += 1;
        }
        ok[0] = true;
        for(int i = 0; i < r; i++)
            for(int j = k; j >= vet[i]; j--)
                if(ok[j - vet[i]])
                    ok[j] = true;
        if(ok[k])
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}
