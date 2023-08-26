/*
    author: Leonardo Deliyannis Constantin
*/

#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string s, t;
    int h = 0;
    while(cin >> s, s != "0"){
        cin >> t;
        h++;
        if(h > 1)
            cout << "\n";
        cout << "Instancia " << h << "\n";
        size_t found = t.find(s);
        if(found != string::npos){
            cout << "verdadeira\n";
        }
        else{
            cout << "falsa\n";
        }
    }
    return 0;
}
