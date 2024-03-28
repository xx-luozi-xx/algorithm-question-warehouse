#include<stdio.h>
int main()
{
    char ch;
    scanf("%c",&ch);
    printf("%c",ch-32);
    //!luozi
    ch+= -'a'+'A';
    ch+= -'A'+'a';
}
