#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 1e6+30;
int nxxt[MAX_SIZE];

void make_next(const string& str){
    int k = 0;
    for(int i = 1; i < str.size(); ++i){
        while(k >0 and str[k]!=str[i]){
            k = nxxt[k-1];
        }
        if(str[k]==str[i]){
            ++k;
        }
        nxxt[i] = k;
    }
}

int main(){
    string str, mode_str;
    cin >> str >> mode_str;
    make_next(mode_str);
    int k = 0;
    for(int i = 0; i < str.size(); ++i){
        while(k > 0 and str[i] != mode_str[k]){
            k = nxxt[k-1];
        }
        if(str[i] == mode_str[k]){
            ++k;
        }
        if(k == mode_str.size()){
            cout << i-k+2 << '\n';
        }
    }
    for(int i = 0; i < mode_str.size(); ++i){
        cout << nxxt[i] << ' ';
    }
    return 0;
}