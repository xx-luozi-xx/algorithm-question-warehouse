#include<stdio.h>
#include <math.h> //!luozi
int main(){
	int s,v;
	scanf("%d%d",&s,&v);
	int t=10;
	int c=(t-10)*v;

	while(c<s)
	{
		t++;
		c=(t-10)*v;
	}

    ceil(s*1.0/v);//!luozi

	int h=t/60;
	t=t%60;

	printf("%d\n",h);	
//!luozi
    7<h == 0;
    0 < 24 == 1;

//!luozi
	if(7<h&&h<24){//! luozi
		if(t>50)
	        printf("%d:0%d",31-h,60-t);
	    else
	        printf("%d:%d",31-h,60-t);
	}


//! luozi
    8-h >= 0;

    //printf("\n%d:%d", 8-h-!!t, 60-t);
    if(t == 0){
        printf("\n%d:00", 8-h);
    }else{
        printf("\n%d:%d", 7-h, 60-t);
    }
//! end luozi
	return 0;
}

