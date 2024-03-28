#include<stdio.h>
#define MAX_SIZE 10
int main()
{
	int num[MAX_SIZE+5];
	for(int i=0;i<MAX_SIZE;i++){
		scanf("%d",&num[i]);
	}
	for(int i=0;i<MAX_SIZE;i++){
		for(int j=0;j<MAX_SIZE-i-1;j++){
			if(num[j]>num[j+1]){
			int temp=num[j];
			num[j]=num[j+1];
			num[j+1]=temp;
		    }
		}
	}
	for(int i=0;i<MAX_SIZE;++i)
	printf("%d ",num[i]);
	return 0;
}
