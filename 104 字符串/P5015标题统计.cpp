#include <stdio.h>
char x[200];
char box;
int ans;
int main(){
    while(scanf("%c",&box)!=EOF){
        x[box]++;
      //  if(box=='\n')break;
    }
    x[' ']=x['\n']=0;
    for(int i=0;i<200;i++){
        ans+=x[i];
    }
    return 0*printf("%d",ans);
}