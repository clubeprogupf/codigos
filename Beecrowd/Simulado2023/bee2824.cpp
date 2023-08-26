/*
    author: Leonardo Deliyannis Constantin
*/

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 5123

int pd[MAX][MAX];
/*
int lcs(const string &s, const string &t, int i, int j){
    if(pd[i][j] != -1)
        return pd[i][j];
    if(i == 0 || j == 0)
        return pd[i][j] = 0;
    if(s[i-1] == t[j-1])
        return pd[i][j] = 1 + lcs(s, t, i-1, j-1);
    return pd[i][j] = 
        max(lcs(s, t, i-1, j), 
            lcs(s, t, i, j-1));
}
*/
void lcs(const string &s, const string &t){
    for(int i = 0; i <= (int) s.size(); i++){
        for(int j = 0; j <= (int) t.size(); j++){
            if(i == 0 || j == 0)
                pd[i][j] = 0;
            else if(s[i-1] == t[j-1])
                pd[i][j] = pd[i-1][j-1] + 1;
            else
                pd[i][j] = max(pd[i-1][j], pd[i][j-1]);
        }
    }
}

int main(){
    string s, t;
    ios_base::sync_with_stdio(false);
    while(getline(cin, s)){
        getline(cin, t);
        // memset(pd, -1, sizeof(pd));
        // int ans = lcs(s, t, s.size(), t.size());
        lcs(s, t);
        int ans = pd[s.size()][t.size()];
        cout << ans << endl;
    }
    return 0;
}
