/*
 * author: Leonardo Deliyannis Constantin
 */

#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
#define MAX 112

int l, c;
string m[MAX][MAX];
int rowSum[MAX], colSum[MAX];

void update(const string &found, int val){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(m[i][j] == found){
                rowSum[i] -= val;
                colSum[j] -= val;
            }
        }
    }
}

int main(){
    while(cin >> l >> c){
        set<string> total;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < c; j++){
                cin >> m[i][j];
                total.insert(m[i][j]);
            }
            cin >> rowSum[i];
        }
        for(int j = 0; j < c; j++){
            cin >> colSum[j];
        }
        map<string, int> known;
        while(known.size() < total.size()){
            for(int i = 0; i < l; i++){
                set<string> unknown;
                int times = 0;
                for(int j = 0; j < c; j++){
                    if(!known.count(m[i][j])){
                        unknown.insert(m[i][j]);
                        times++;
                    }
                }
                if(unknown.size() == 1){
                    string found = *unknown.begin();
                    known[found] = rowSum[i] / times;
                    update(found, known[found]);
                }
            }
            for(int j = 0; j < c; j++){
                set<string> unknown;
                int times = 0;
                for(int i = 0; i < l; i++){
                    if(!known.count(m[i][j])){
                        unknown.insert(m[i][j]);
                        times++;
                    }
                }
                if(unknown.size() == 1){
                    string found = *unknown.begin();
                    known[found] = colSum[j] / times;
                    update(found, known[found]);
                }
            }
        }
        for(auto var : known){
            cout << var.first << " " << var.second << endl;
        }
    }
    return 0;
}
