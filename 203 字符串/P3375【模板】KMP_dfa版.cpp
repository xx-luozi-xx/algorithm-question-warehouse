#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
const int MAX_SIZE = 1e6+30;
unordered_map<char, int> dfa[MAX_SIZE];
vector<int> Xs;
void make_dfa(const string& str){
    dfa[0][str[0]] = 1;
    int X = 0; Xs.push_back(X); 
    for(int i = 1; i <= str.size(); ++i){
        for(int j = 'A'; j <= 'Z'; ++j){
            if(i < str.size() and j == str[i]){
                dfa[i][j] = i+1;
            }else{
                dfa[i][j] = dfa[X][j];
            }
        }
        X = dfa[X][str[i]]; Xs.push_back(X);
    }
    Xs.pop_back();
}

int main(){
    string str, mode_str;
    cin >> str >> mode_str;
    make_dfa(mode_str);
    int p = 0;
    for(int i = 0; i < str.size(); ++i){
        p = dfa[p][str[i]];
        if(p == mode_str.size()){
            cout << i-int(mode_str.size())+2 << '\n';
        }
    }
    for(int i = 0; i < Xs.size(); ++i){
        cout << Xs[i] <<' ';
    }
    return 0;
}