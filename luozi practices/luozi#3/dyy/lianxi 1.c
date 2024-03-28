#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n],temp,b,min,max;
    min = 0x7fffffff;
    max = 0x80000000;
    for(int i=0;i<n;i++){
        //scanf("%d",&a[i]);
        int input; scanf("%d", &input);
        (input > max)?(max = input):(0);
        input < min? min = input:0;

        //max = max(input, max);
        //min = min(input, min);

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    min=a[0];
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]<a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    max=a[0];
    b=max-min;
    printf("%d",b);
    return 0;
}