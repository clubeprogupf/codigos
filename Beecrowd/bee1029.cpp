/*
 * author: Leonardo Deliyannis Constantin
 */

#include <stdio.h>

int calls;

int fib(int x){
	calls++;
	if(x <= 1)
	    return x;
	return(fib(x-1) + fib(x-2));
}

int main(){
	int n, x, ans;
	scanf("%d", &n);
	while(n--){
		calls = -1;
		scanf("%d", &x);
		ans = fib(x);
		printf("fib(%d) = %d calls = %d\n", x, calls, ans);
	}
	return 0;
}
