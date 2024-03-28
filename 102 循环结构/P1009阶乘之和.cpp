#include <stdio.h>
int a[3000]={0}, sum[3000]={0},p1;
int main(){
    int n,j;scanf("%d",&n);
    a[0]=1,a[1]=-1,sum[0]=-1;
    for(int i=1;i<=n;i++){
        for(j=0;a[j]!=-1;j++){//乘
            a[j]*=i;
        }
        for(j=0;a[j+1]!=-1;j++){//进位到尾
            a[j+1]+=a[j]/10;
            a[j]%=10;
        }
        while(a[j]/10){//尾巴进位完
            a[j+1]=a[j]/10,a[j]%=10,a[j+2]=-1,j++;
            }
        for(j=0;a[j]!=-1;j++){//加和
            if(sum[j]==-1)sum[j]=0,sum[j+1]=-1;
            sum[j]+=a[j];
        }
        for(j=0;sum[j+1]!=-1;j++){//进位到尾
            sum[j+1]+=sum[j]/10;
            sum[j]%=10;
        }
        while(sum[j]/10){//尾巴进位完
        sum[j+1]=sum[j]/10,sum[j]%=10,sum[j+2]=-1,j++;
            }
    }
    for(j=0;sum[j]!=-1;j++);//大到小输出
    for(j--;j>=0;j--)printf("%d",sum[j]);
}