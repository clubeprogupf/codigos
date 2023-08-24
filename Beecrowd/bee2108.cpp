/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>
#include<string.h>
#define MAX 112

int main(){
    char s[MAX], big[MAX];
    char* t;
    int v[MAX], i, sz;
    big[0] = '\0';
    while(fgets(s, MAX, stdin) != NULL){
        s[strlen(s)-1] = '\0';
        if(strcmp(s, "0") == 0)
            break;
        sz = 0;
        t = strtok(s, " ");
        while(t != NULL){
            v[sz++] = strlen(t);
            if(v[sz-1] >= (int)strlen(big)){
                strcpy(big, t);
            }
            t = strtok(NULL, " ");
        }
        for(i = 0; i < sz; i++){
            printf("%d%c", v[i], i < sz-1 ? '-' : '\n');
        }
    }
    printf("\nThe biggest word: %s\n", big);
    return 0;
}
