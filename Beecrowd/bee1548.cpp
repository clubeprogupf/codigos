/*
 * author: Leonardo Deliyannis Constantin
 */

#include <stdio.h> // scanf, printf
#include <algorithm> // sort
#include <functional> // greater<int>
using namespace std;
#define MAX 1123

int main(){
	int n, m, v[MAX], u[MAX];
	scanf("%d\n", &n);
	while(n--){
		scanf("%d\n", &m);
		for(int i = 0; i < m; i++){
			scanf("%d", &v[i]);
            u[i] = v[i];
        }
		sort(v, v+m, greater<int>());
        int c = 0;
		for(int i = 0; i < m; i++)
			if(v[i] == u[i])
                c++;
		printf("%d\n", c);
	}
	return 0;
}
