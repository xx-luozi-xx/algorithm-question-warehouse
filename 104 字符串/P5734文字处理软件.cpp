#include <stdio.h>
#include <string.h>
char a[2333];
int n;
int mode;
int main(){
    scanf("%d\n",&n);
    scanf("%s\n",a);
    while(n--){
        scanf("%d ",&mode);
        if(mode==1){
            char box[233];
            scanf("%s",box);
            strcat(a,box);
            printf("%s\n",a);
        }else if(mode == 2){
            int aa,b;
            scanf("%d %d",&aa,&b);
            for(int i=0;i<b;i++){
                a[i]=a[i+aa];
            }
            a[b]='\0';
            printf("%s\n",a);
        }else if(mode == 3){
            int b;
            char box[233];
            char real[2333];
            scanf("%d %s",&b,box);
            strncpy(real,a,b);
            real[b]=0;
            //printf("--%s--\n",real);
            strcat(real,box);
           // printf("--%s--\n",real);
            strcat(real,a+b);
            //printf("--%s--\n",real);
            strcpy(a,real);
            printf("%s\n",a);
        }else{
            char box[233];
            scanf("%s",box);
            char* x=strstr(a,box);
            if(x==NULL){
                printf("-1\n");
            }else{
                printf("%d\n",x-a);
            }
        } 
    }
    return 0;
}