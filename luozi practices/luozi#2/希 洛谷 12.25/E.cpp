#include<stdio.h>
int main()
{
	int t1[10],t2[10],sum[10];
	for(int i=0;i<7;i++){
		scanf("%d",&t1[i]);
		scanf("%d",&t2[i]);
		sum[i]=t1[i]+t2[i];
	}
	//*离线做法(全部存入后，再处理)

	//*在线做法(一边输入，一遍处理(甚至输出))
	int flag=0,max=0;
	int day;
	for(int i=0;i<7;i++){
		if(sum[i]>8){
			flag++;
		    if(max<sum[i]){
		        max=sum[i];
		        day=i+1;	
			}
		}
	}
	if(flag==0)
		printf("0");
	else
		printf("%d",day);
	return 0;
}
