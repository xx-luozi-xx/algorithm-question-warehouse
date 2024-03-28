#include <stdio.h>
#include <string.h>
int position, ans, p = -1, Lposition;
char word[233];
char getone(){
    char box;
    int out = scanf("%c", &box);
    if(out == EOF||box == '\n'){
        return -1;
    }else if(box == ' '){
        position++;
        return 0;
    }
    position++;
    return box >= 'a' ? box - ('a' - 'A') : box;
}
int getword(){
    int L=0;
    while(1){
        char box = getone();
        
        if(box == 0){
            word[L] = 0;
            return 0;
        }else if(box == -1){
            word[L] = 0;
            return -1;
        }

         word[L++] = box;      
    }
}

int main(){
    char Iword[233] = {0};
    int L = 0;
    while(1){
        char box = getone();
        if(box <= 0){
            Iword[L] = 0;
            break;
        }
         Iword[L++] = box;      
    }
  
    position = 0;

    while(getword()!=-1){
        int x = strcmp(Iword,word);
        ans += !x;
        if(!x&&p==-1){
            p = Lposition;
        }
        Lposition = position;
    }
    
    if(ans){
        return 0*printf("%d %d",ans,p);
    }else{
        return 0*printf("-1");
    }
}