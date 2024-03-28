#include <stdio.h>
struct tree {
    int a = 0;
    int b = 0;
}x[10000+233],box;
int main(){
    int l,n,ans=0;
    scanf("%d %d",&l,&n);
    for(int i = 0; i < n; scanf("%d %d",&x[i].a,&x[i].b),i++);
    for(int i=n-1; i>0; i--){
        for(int j=0; j<=i-1; j++){
            x[j].a>x[j+1].a?box=x[j],x[j]=x[j+1],x[j+1]=box,0:0;
        }
    }
    for(int i=0;i<n;i++){
        if(i==n-1||x[i].b<x[i+1].a){
            ans+=x[i].b-x[i].a+1;
        }else{
           x[i+1].a=x[i].a;
           x[i+1].b=x[i+1].b>x[i].b?x[i+1].b:x[i].b;
        }
    }
    return 0*printf("%d",l+1-ans);
}
/*
#include<stdio.h>
int l, n, t[10000+233],ans;
int main(){
    scanf("%d %d",&l,&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        for(int i=a;i<=b;t[i++]=1);
    }
    for(int i=0;i<=l;ans+=t[i++]);
    return 0*printf("%d",l+1-ans);
}
*/