#include <bits/stdc++.h>
using namespace std;
string s1, s2;

int tree[50], tree_size = 1;
int l[50];
int r[50];

int mid = 0;
int make_tree(int L, int R)noexcept{
    int idx = tree_size++;
    tree[idx] = s2[mid];
    for(int i = L; i <= R; ++i){
        if(s1[i] == s2[mid]){
            if(L <= i-1){
                mid++;
                l[idx] = make_tree(L, i-1);
            }
            if(i+1 <= R){
                mid++;
                r[idx] = make_tree(i+1, R);
            }
            return idx;
        }
    }
}

void print(int now)noexcept{
    if(l[now]){
        print(l[now]);
    }
    if(r[now]){
        print(r[now]);
    }
    cout << char(tree[now]);
}

int main(){
    cin >> s1 >> s2;
    int root = make_tree(0, s1.size()-1);
    print(root);
    return 0;
}