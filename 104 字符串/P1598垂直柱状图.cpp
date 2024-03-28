#include <stdio.h>
bool out['Z'-'A'+5][500];
int ans['Z'-'A'+5];
int main(){
    char ptr;
    //int end=3;
    while(scanf("%c",&ptr)!=EOF/*&&ptr!='0'*/){
        if(ptr>='A'&&ptr<='Z'){
            ptr-='A';
            out[ptr][ans[ptr]++]=1;
        }
    }

    int max=0;
    for(int i:ans){
        i>max?max=i:0;
    }

    for(int i = max-1;i>=0;i--){
        for(int j = 0;j<='Z'-'A';j++){
            printf("%c",out[j][i]?'*':' ');
            j=='Z'-'A'?printf("\n"):printf(" ");
        }
    }
    for(int j = 0;j<='Z'-'A';j++){
        printf("%c",'A'+j);
        j=='Z'-'A'?0:printf(" ");
    }
}