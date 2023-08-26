/*
    author: Leonardo Deliyannis Constantin
*/

#include<iostream>
#include<vector>
#include<cmath> // math.h
#include<algorithm>
#include<set>
#include<stack>
using namespace std;
#define MAX 152345

struct circle{
    double x, y, r;
    circle(){ 
        x = y = r = 0.0;
    }
    circle(double _x, double _y, double _r){ 
        x = _x, y = _y, r = _r;
    }
    bool contains(const circle &o) const{
        return hypot(x - o.x, y - o.y) + o.r < r;
    }
    bool operator < (const circle &o) const{
        return r <= o.r;  
    }
};

int n;
circle c[MAX];
vector<int> LG[MAX];
int ans;

void dfs(int s, int orig){
    stack<int> st;
    st.push(s);
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(c[orig].contains(c[u]))
            continue;
        ans += 2;
        if(ans > 2*n)
            break;
        for(int v : LG[u]){
            st.push(v);
        }
    }
}
/*
void dfs(int u, int orig){
    ans += 2;
    if(ans > 2*n)
        return;
    for(int v : LG[u]){
        if(c[orig].contains(c[v]))
            continue;
        dfs(v, orig);
        if(ans > 2*n)
            return;
    }
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    while(cin >> n){
        for(int i = 0; i < n; i++){
            LG[i].clear();
            double x, y, r;
            cin >> x >> y >> r;
            c[i] = circle(x, y, r);
        }
        sort(c, c+n);
        ans = 0;
        set<int> roots;
        for(int i = 0; i < n; i++){
            vector<int> marked;
            if(ans > 2*n) break;
            for(int rt : roots){
                if(c[i].contains(c[rt])){
                    LG[i].push_back(rt);
                    marked.push_back(rt);
                }
                else{
                    dfs(rt, i);
                    if(ans > 2*n)
                        break;
                }
            }
            for(int mk : marked){
                roots.erase(mk);
            }
            roots.insert(i);
        }
        if(ans <= 2*n){
            cout << ans << "\n";
        }
        else{
            cout << "greater\n";
        }
    }
    return 0;
}
