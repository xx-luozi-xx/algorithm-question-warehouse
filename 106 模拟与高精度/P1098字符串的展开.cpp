#include <stdio.h>
#include <string.h>
char a[2333];
char out[23333];
int ans;
char p1,p2,p3;
int main(){
    scanf("%hd %hd %hd\n",&p1,&p2,&p3);
    scanf("%s",a);
    for(int i = 0; i<strlen(a);i++){
        if(a[i]!='-'||a[i]==0) {out[ans++]=a[i];}
        if(a[i]=='-'){
            if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i+1]>a[i-1]){//字母
                if(p3==1){//顺序
                    for(int j = a[i-1]+1;j<a[i+1];j++){
                        for(int k = 0;k<p2;k++){
                            out[ans++]=(p1==3?'*':j+(p1==2)*('A'-'a'));
                        }
                    }
                }else{//逆序
                    for(int j = a[i+1]-1;j>a[i-1];j--){
                        for(int k = 0;k<p2;k++){
                            out[ans++]=(p1==3?'*':j+(p1==2)*('A'-'a'));
                        }
                    }
                }
            }else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i+1]>a[i-1]){//数字
                if(p3==1){//顺序
                    for(int j = a[i-1]+1;j<a[i+1];j++){
                        for(int k = 0;k<p2;k++){
                            out[ans++]=(p1==3?'*':j);
                        }
                    }
                }else{//逆序
                    for(int j = a[i+1]-1;j>a[i-1];j--){
                        for(int k = 0;k<p2;k++){
                            out[ans++]=(p1==3?'*':j);
                        }
                    }
                }
            }else{//不替换
                 out[ans++]=a[i];   
            }
        }
    }
    return 0*printf("%s",out);
}