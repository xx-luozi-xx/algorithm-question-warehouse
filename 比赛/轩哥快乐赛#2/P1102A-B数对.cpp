/**
 * @file P1102A-B数对.cpp
 * @author luozi
 * @brief 轩哥快乐赛#2
 * @version 0.1
 * @date 2022-10-20
 * 
 * @copyright xX_luozi_Xx (c) 2022
 * 
 */
#include <algorithm>
#include <iostream>
using namespace std;
int a[2*100000+5];
int N, C;
int findl(int x){
    int l = 0, r = N-1;
    while(l<=r){
        int mid = (r+l)/2;
        if(a[mid]==x&&(mid+1==N||a[mid+1]>x)){
            return mid;
        }else if(a[mid]>x){//缩小mid
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return -1;
}
int findf(int x){
    int l = 0, r = N-1;
    while(l<=r){
        int mid = (r+l)/2;
        if(a[mid]==x&&(mid==0||a[mid-1]<x)){
            return mid;
        }else if(a[mid]<x){//缩小mid
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return 0;
}
int main(){
    cin>>N>>C;
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }
    sort(a,a+N);
    unsigned long long out = 0;
    for(int i = 0; i < N; ++i){
        out+=findl(a[i]+C)-findf(a[i]+C)+1;
    }
    return printf("%llu",out)*0;
}
