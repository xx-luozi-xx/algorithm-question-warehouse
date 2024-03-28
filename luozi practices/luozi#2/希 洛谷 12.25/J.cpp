#include<stdio.h>
int main(){
	char str[15];
	scanf("%s",str);
	int sum=0,j=1;
	for(int i=0;i<11;i++){
		if(str[i]!='-'){
			sum+=(str[i]-'0')*j;
			j++;			
		}
	}
    int n=sum%11;
	char str0[12]={"0123456789X"};

	//!luozi
	str[12]=='X'?str[12]='9'+1:0;
	//!end luozi
	if(n==(str[12]-'0'))                    
		printf("Right");
	else{
		str[12]=str0[n];
		printf("%s",str);
	}
	return 0;	
}
