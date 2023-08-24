/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 11234
using namespace std;

int main(){
	int n, q;
	int t = 0;
	int query;
	while(cin >> n >> q, n != 0 && q != 0){
		t++;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		cout << "CASE# " << t << ":" << endl;
		while(q--){
			cin >> query;
			auto it = lower_bound(v.begin(), v.end(), query);
			cout << query;
			if(it == v.end() || *it != query){
				cout << " not found";
			}
			else{
				cout << " found at " << it - v.begin() + 1;
			}
			cout << endl;
		}
	}
	return 0;
}
