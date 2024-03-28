#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> data;

int main(){
    int n,m;scanf("%d %d",&n, &m);
    for(int i=0; i<m;++i){
        int box;scanf("%d",&box);
        data.push_back(box);
    }
    std::sort(data.begin(),data.end());
    for(int i = 0; i<m; ++i){
        printf("%d ",data[i]);
    }
    return 0;
}