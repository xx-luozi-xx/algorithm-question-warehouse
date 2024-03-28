#include<stdio.h>
struct door{
    char name[12];
    int face;
    door() = default;
    void get(){
        scanf("%d %s",&face,name);
        face= (face*2-1);
    }
    int print(){
        return printf("%s",name);
    }
};
door a[100000];
int main(){
    int ptr = 0;
    int n,m;scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        a[i].get();
    }
    while(m--){
        int face, go;scanf("%d %d",&face,&go);
        face= -(face*2-1)*a[ptr].face;
        ptr+=go*face;
        while(ptr<0||ptr>=n){
            ptr = (ptr+n)%n;
        }
    }
    a[ptr].print();
    return 0;   
}