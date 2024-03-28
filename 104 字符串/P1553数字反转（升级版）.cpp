#include <stdio.h>
#include <string.h>

void trun(char *a){
    char b[233];
    strcpy(b,a);
    for(int i=0;i<strlen(b);i++){
        a[i]=b[strlen(b)-1-i];
    }
}
void cut(char *a, int mode=0){
    if(strlen(a)==1){
        return;//仅剩一个0不需要舍去0
    }
    if(mode){
        for(int i=strlen(a)-1;i>=0;i--){
            if(a[i]=='0'){
                a[i]=0;
                return;
            }
        }
    }else{
        char b[233];
        for(int i=0;i<strlen(a);i++){
            if(a[i]=='0'){
                continue;
            }else{
                strcpy(b,a+i);
                strcpy(a,b);
                return;
            }
        }
    }
}

int main(){
    char a[233];int ans=0;
    char b[233];
    char mode='0';

    while(1){
        char box;
        int out = scanf("%c",&box);
        if(out == -1||box=='\n'){
            a[ans]=0;
            break;
        }
        if(box>='0'&&box<='9'){
            a[ans++]=box;
        }else{
            a[ans]=0;
            mode=box;
            break;
        }
    }
    //printf("%c\n",mode);
    if(mode == '0'){
        trun(a);
        cut(a);
        return 0*printf("%s",a);
    }else if(mode == '%'){
        trun(a);
        cut(a);
        return 0*printf("%s%c",a,'%');//%号不好输出
    }else if(mode == '.'){
        scanf("%s",b);
        trun(a);
        cut(a);
        trun(b);
        cut(b,1);
        return 0*printf("%s.%s",a,b);
    }else{
        scanf("%s",b);
        trun(a);
        cut(a);
        trun(b);
        cut(b);
        return 0*printf("%s/%s",a,b);
    }
}