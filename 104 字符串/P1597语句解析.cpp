#include <stdio.h>
int main(){
	int a[3]={0};
	char ia, ib;
	while(scanf("%c:=%c;",&ia,&ib)!=EOF){
		ia-='a';
		if(ib>='a'){
			ib-='a';
			a[ia]=a[ib];
		}else{
			a[ia]=ib-'0';
		}
	}
	for(int i:a){
		printf("%d ",i);
	}
	return 0;
	}