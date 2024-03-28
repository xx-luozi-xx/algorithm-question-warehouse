#include <stdio.h>
#include <algorithm>

int arr[102000];

void sort(int* l, int * r);

int main(){
    int N; scanf("%d",&N);
    for(int i = 0; i<N; i++) scanf("%d", &arr[i]);
    //std::random_shuffle(arr,arr+N);//打乱顺序防止黑心数据
    sort(arr,arr+N);
    for(int i = 0; i<N; i++) printf("%d ",arr[i]);
    return 0;
}

void sort(int* lhs, int* rhs){//(lhs,rhs]
    int*a = lhs;
    int l=0, i=0;
    int r=rhs-lhs-1, j=rhs-lhs-1;

    int mid = a[(l+r)/2];

    while(1){
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;

        if(i<=j){//等于时也做一遍，使得控制区间错开，方便递归取区间和防止同一值递归死循环
            std::swap(a[i],a[j]);
            i++,j--;
        }
        if(i>j){
            break;
        }   
    }
    if(l<j) sort(lhs, lhs+j+1);
    if(i<r) sort(lhs+i, rhs);
}