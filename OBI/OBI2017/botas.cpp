#include<iostream>
#define MAX 31

int main(){
	int N, M, i;
	int pares;
	char C;
	int esq[MAX], dir[MAX];
	while(cin >> N){
		for(i = 0; i < MAX; i++){
			esq[i] = dir[i] = 0;
		}
		while(N--){
			cin >> M >> C;
			C == 'E' ? esq[M-30]++ : dir[M-30]++;
		}
		pares = 0;
		for(i = 0; i < MAX; i++){
			if(esq[i] == dir[i]) pares += esq[i];
		}
		cout << pares << endl;
	}
	return 0;
}
