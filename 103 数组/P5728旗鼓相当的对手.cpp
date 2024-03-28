/*
#include <stdio.h>
#include <math.h>
struct sdu{
    int a,b,c;
}a[1000+233];
int main(){
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(abs(a[i].a-a[j].a)<=5&&abs(a[i].b-a[j].b)<=5&&abs(a[i].c-a[j].c)<=5){
                abs(a[i].a+a[i].b+a[i].c-a[j].a-a[j].b-a[j].c)<=10?ans++:0;
            }
        }
    }
    return 0*printf("%d",ans);
}
*/
#include <stdio.h>
#include <cmath>
struct stu{
    int a,b,c,all;
}a[1000+233];
int add(struct stu &a){
    return a.all=a.a+a.b+a.c;
}
int swap(struct stu &a, struct stu &b){
    struct stu box = a;
    return a = b, b = box, 0;
}
int main(){
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
        add(a[i]);
    }
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            a[j].all>a[j+1].all?swap(a[j],a[j+1]):0;
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j].all-a[i].all>10) break;
            if(abs(a[i].a-a[j].a)<=5&&abs(a[i].b-a[j].b)<=5&&abs(a[i].c-a[j].c)<=5){
                ans++;
            }
        }
    }
    return 0*printf("%d",ans);
}