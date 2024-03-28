#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 2e4 * 2 + 30;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
vector<int> eage[MAX_SIZE];
int n, m;

int vit[MAX_SIZE];
void dfs(int now){
    vit[now] = 1;
    for(int i = 0; i < eage[now].size(); ++i){
        if(vit[eage[now][i]] == 0){
            dfs(eage[now][i]);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        eage[a].push_back(b);
    }
    dfs(1);
    cout << (vit[n]?"Yes":"No");
}