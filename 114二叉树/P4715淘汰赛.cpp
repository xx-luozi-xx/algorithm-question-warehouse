#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1<<8;
int n;
int data[MAX_N];

int make_tree(int root)noexcept{
    if(root >= n){
        return data[root];
    }else{
        int a = make_tree(root<<1);
        int b = make_tree((root<<1)+1);
        data[root] = min(a, b);
        return max(a, b);
    }
}

int main(){
    cin >> n;
    n = 1<<n;
    for(int i = n; i < n+n; ++i){
        cin >> data[i];
    }
    make_tree(1);
    for(int i = n; i < n+n; ++i){
        if(data[1] == data[i]){
            cout << i-n+1;
            return 0;
        }
    }
}