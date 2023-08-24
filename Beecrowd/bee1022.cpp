/*
 * author: Leonardo Deliyannis Constantin
 */

#include<stdio.h>

struct racional{
    int num, den;  
};

racional sum(racional n1, racional n2){
    racional ret;
    ret.num = n1.num * n2.den + n2.num * n1.den;
    ret.den = n1.den * n2.den;
    return ret;
}

racional subtract(racional n1, racional n2){
    racional ret;
    ret.num = n1.num * n2.den - n2.num * n1.den;
    ret.den = n1.den * n2.den;
    return ret;
}

racional multiply(racional n1, racional n2){
    racional ret;
    ret.num = n1.num * n2.num;
    ret.den = n1.den * n2.den;
    return ret;
}

racional divide(racional n1, racional n2){
    racional ret;
    ret.num = n1.num * n2.den;
    ret.den = n2.num * n1.den;
    return ret;
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

racional simplify(racional r){
    int d = gcd(r.num, r.den);
    r.num /= d;
    r.den /= d;
    if(r.den < 0){
        r.num *= -1;
        r.den *= -1;
    }
    return r;
}

int main(){
    int t;
    racional n1, n2, ans;
    char op;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %*c %d %c %d %*c %d",
            &n1.num, &n1.den, &op, &n2.num, &n2.den);
        switch(op){
            case '+':
                ans = sum(n1, n2);
                break;
            case '-':
                ans = subtract(n1, n2);
                break;
            case '*':
                ans = multiply(n1, n2);
                break;
            case '/':
                ans = divide(n1, n2);
                break;
        }
        printf("%d/%d = ", ans.num, ans.den);
        ans = simplify(ans);
        printf("%d/%d\n", ans.num, ans.den);
    }
    return 0;
}
