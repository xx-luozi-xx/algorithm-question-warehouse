#include <stdio.h>
int main(){
	int n; scanf("%d", &n);
  	int ans = 0;
  	while(n--){
    	int a; scanf("%d", &a);
      	if(a > ans){
        	ans = a;
        }
    }
  	printf("%d", ans);
  	return 0;
}