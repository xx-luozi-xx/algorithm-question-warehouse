#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int p[5];
	scanf("%d",&n);
    for(int i=0;i<3;i++){
    	int a,b,c;
    	scanf("%d%d",&a,&b);
    	p[i]=ceil(n/(a*1.0))*b;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3-i-1;j++)
			if(p[j]>p[j+1]){
				int temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
		}
	}
	printf("%d",p[0]);
    return 0;
}
