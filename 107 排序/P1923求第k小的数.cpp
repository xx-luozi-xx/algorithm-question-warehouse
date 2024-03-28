#include <stdio.h>

template<class T>
void swap(T& a, T&b){
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
void nth_element(T *begin, T *right, T *end){
    int k = right - begin;
    int l = 0, r = end-begin-1;
    int i = 0, j = r;

    T mid = begin[(r+l)/2];

    while(1){
        while(begin[i]<mid)++i;
        while(begin[j]>mid)--j;

        if(i<=j){
            swap(begin[i], begin[j]);
            ++i,--j;
        }
        if(i>j){
            break;
        }
    }

    if(j<k&&k<i){
        return ;
    }else if(k<=j){
        return nth_element(begin, right, begin+j+1);
    }else{
        return nth_element(begin+i,right,end);
    }
}

int main(){
    int n, k;scanf("%d %d",&n,&k);
    int* arr = new int[n+1];
    for(int i = 0; i<n; scanf("%d",&arr[i++]));

    nth_element(arr, arr+k, arr+n);
    printf("%d", arr[k]);
    
    delete[] arr;
    return 0;
}
