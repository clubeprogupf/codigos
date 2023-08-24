/*
 * author: Leonardo Deliyannis Constantin
 */

#include<bits/stdc++.h>
/* #include <stdio.h> 
#include <string.h>
#include <algorithm> */
using namespace std;
#define MAX 112

void insideOut(char *s){
    int n = strlen(s) - 1;
    int half = n/2;
    for(int i = 0; i < half/2; i++){
        swap(s[i], s[half-1-i]);
    }
    for(int i = half; i < n*3/4; i++){
        swap(s[i], s[n-1 - (i-half)]);
    }
}

int main(){
    int t;
    char s[MAX];
    scanf("%d%*c", &t);
    while(t--){
        fgets(s, MAX, stdin);
        insideOut(s);
        printf("%s", s);
    }
    return 0;
}
