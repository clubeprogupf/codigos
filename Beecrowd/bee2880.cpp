/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<string.h>
#define MAX 11234

int solve(const char *s, const char *t){
    int ns = strlen(s);
    int nt = strlen(t);
    int ans = 0;
    for(int i = 0; i <= (ns - nt); i++){
        bool flag = true;
        for(int j = 0; j < nt; j++){
            if(s[i+j] == t[j]){
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }
    return ans;
}

int main(){
    char s[MAX], t[MAX];
    while(scanf("%s", s) != EOF){
        scanf("%s", t);
        printf("%d\n", solve(s, t));
    }
    return 0;
}
