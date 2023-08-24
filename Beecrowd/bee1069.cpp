/*
 * author: Leonardo Deliyannis Constantin
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n, i, diamonds;
    string str;
    stack<int> p;
    cin >> n;
    while(n--){
        cin >> str;
        diamonds = 0;
        for(i = 0; i < (int)str.size(); i++){
            if(str[i] == '<')
                p.push(1);
            if(str[i] == '>' && p.size() > 0){
                p.pop();
                diamonds++;
            }
        }
        while(!p.empty())
            p.pop();
        cout << diamonds << endl;
    }
}
