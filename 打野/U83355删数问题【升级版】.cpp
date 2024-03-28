#pragma GCC optimize(2) 

#include <stdio.h>
#include <ctype.h>
#include <list>
using namespace std;

int main(){
    int N; scanf("%d\n", &N);
    while(N--){
        list<char> str;
        str.push_back(0);
        while(1){
            char input=getchar();
            if(input == '\n'){
                break;
            }
            str.push_back(input);
        }
        str.push_back(0);
        int n; scanf("%d\n", &n);
        int delet = 0;
        for(auto itr_n = str.begin(), itr = itr_n++; itr_n!=str.end();){
            if(*itr>*itr_n){
                itr = str.erase(itr);
                itr_n = itr--;
                delet++;
                if(delet == n){
                    break;
                }
            }else{
                itr_n++;
                itr++;
            }
        }
        bool start = false;
        for(auto itr = str.begin(); itr!=str.end(); ++itr){
            if(isprint(*itr)){
                if(start || *itr != '0'){
                    start = true;
                    putchar(*itr);
                }
            }
        }
        if(!start){
            putchar('0');
        }
        putchar('\n');
    }
    return 0;
}