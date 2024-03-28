#include <iostream>
#include <string>
using namespace std;
int cnt[100];
int main(){
    int n; cin >>n;
    string str; cin >> str;
    for(int i = 0; i < n; ++i){
        cnt[str[i]-'0']++;
    }
    if(cnt[2]==cnt[0]and cnt[2]==cnt[1]and cnt[2]==cnt[4] and cnt[2]*4==n){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}