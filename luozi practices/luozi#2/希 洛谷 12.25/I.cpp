#include<stdio.h>
int main(){
	int b[5];
	for(int i=0;i<3;i++){
		scanf("%d",&b[i]);
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3-i-1;j++){
			if(b[i]>b[i+1]){
				int temp=b[i];
				b[i]=b[i+1];
				b[i+1]=temp;
			}
		}
	}
	if(b[0]+b[1]<=b[2])
		printf("Not triangle\n");
	else{
		int s=b[0]*b[0]+b[1]*b[1];
	    if(s==b[2]*b[2])
	    	printf("Right triangle\n");
	    if(s>b[2]*b[2])
	    	printf("Acute triangle\n");
	    if(s<b[2]*b[2])
	    	printf("Obtuse triangle\n");
	    if(b[0]==b[1]||b[1]==b[2])
	    	printf("Isosceles triangle\n");
	    if(b[0]==b[1]&&b[0]==b[2])
	    	printf("Equilateral triangle\n");
	}
	return 0;	
}
