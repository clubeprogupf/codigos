/*
 * author: Leonardo Deliyannis Constantin
 */

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 231

int main(){
	int t, n, h, i;
	int c[MAX];
	bool first;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		memset(c, 0, sizeof(c));
		while(n--){
			cin >> h;
			c[h]++;
		}
		first = true;
		for(i = 20; i < MAX; i++){
			while(c[i]--){
				if(first) 
					first = false;
                else 
					cout << ' ';
				cout << i;
			}
		}
		cout << endl;
	}
	return 0;
}
