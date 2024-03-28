#include <stdio.h>
#include <string.h>
int main(){
    int boy=0,girl=0;
    char a[233]={0};
    scanf("%s",a);
    int n=strlen(a);
    for(int i=0;i<n;i++){
        if(a[i]=='b'){
            boy++;
            int ans=0;
            a[i+1]=='o'?ans++:0;
            a[i+2]=='y'?ans++:0;
            i+=ans;
        }else if(a[i]=='o'){
            boy++;
            a[i+1]=='y'?i++:0;
        }else if(a[i]=='y'){
            boy++;
        }else if(a[i]=='g'){
            girl++;
            int ans=0;
            a[i+1]=='i'?ans++:0;
            a[i+2]=='r'?ans++:0;
            a[i+3]=='l'?ans++:0;
            i+=ans;
        }else if(a[i]=='i'){
            girl++;
            int ans=0;
            a[i+1]=='r'?ans++:0;
            a[i+2]=='l'?ans++:0;
            i+=ans;
        }else if(a[i]=='r'){
            girl++;
            a[i+1]=='l'?i++:0;
        }else if(a[i]=='l'){
            girl++;
        }
    }
    return 0*printf("%d\n%d",boy,girl);
}