#include<stdio.h>
int main(){
	int x,n;
	int flag=0;
	scanf("%d%d",&x,&n);
	int s1=(n/7)*250*5;
	for(int i=x;i<x+(n%7);i++){
		int m=i;
		if(m>7){
			m-=7;
		}
		if(m==6||m==7)
			flag++;
	}
	int s2=((n%7)-flag)*250;
	printf("%d",s1+s2);
	return 0;
}
