#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    cin >> n;
    for (; n > 0; n--)
    {
        for (int i = 1, j = n; i <= n; i++)
        {
            if (i + sum < 10)
                cout << "0" << i + sum;
            else
                cout << i + sum;
        }
        sum += n;
        cout << endl;
    }
    return 0;
}
#include <stdio.h>
int main(){
    int n,p=1;scanf("%d",&n);
    while(n--){
        for(int i=n+1;i--;)
            p<10?printf("0%d",p++):printf("%d",p++);
        printf("\n");
    }
}