#include <stdio.h>
int a[1000005];
int n, m;
int find_first_of(int k){
    int l = 0, r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]==k&&(mid==0||a[mid-1]<k)){
            return mid+1;
        }else if(a[mid]<k){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return -1;
}
int main(){
    scanf("%d %d",&n, &m);
    for(int i = 0; i<n; ++i){
        scanf("%d",&a[i]);
    }
    while(m--){
        int box; scanf("%d",&box);
        int out = find_first_of(box);
        printf("%d ",out);
    }
    return 0;
}