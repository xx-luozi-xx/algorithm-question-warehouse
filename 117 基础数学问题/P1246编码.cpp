#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 50;

long long c[MAX_SIZE][MAX_SIZE];

int main(){
    string str;
    cin >> str;
    if(str.size() > 6){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < str.size()-1; ++i){
        if(str[i] >= str[i+1]){
            cout << 0;
            return 0;
        }
    }

    c[0][0] = 1;
    for(int i = 1; i < MAX_SIZE-1; ++i){
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }

    long long sum = 0;
    for(int i = 1; i < str.size(); ++i){
        sum += c[26][i];
    }

    for(int i = 0; i < str.size(); ++i){
        int mast = i==0?(str[i]-'a'):(str[i]-str[i-1]-1);
        int all  = i==0?26:('z'-str[i-1]);
        int need = str.size()-i;

        sum += c[all][need]-c[all-mast][need];
    }

    cout << sum+1;

    return 0;
}
