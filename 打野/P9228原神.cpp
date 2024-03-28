#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1e6*2;
int n, m, k;

int a[MAX_SIZE];
int b[MAX_SIZE];


int main(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a+i);
	}
	for(int i = 1; i <= m; ++i){
		scanf("%d", b+i);
	}
	
	sort(a+1, a+n+1, greater<int>());
	
//	for(int i = 1; i <= n; ++i){
//		printf("%d ", a[i]);
//	}printf("\n");
//	
	long long ans = 0;
	
	if(m >= n){
		for(int i = 1; i <= n; ++i){
			if(a[i] > k){
				ans += b[i];
				ans += 2*a[i];				
			}else{
				ans += a[i];
				ans += b[i]+k;
			}
		}
		for(int i = n+1; i <= m; ++i){
			ans += b[i];
		}
		
	}else{

		for(int i = 1; i <= m; ++i){
//			printf("[%d %d]\n", a[i], b[i]);
			if(a[i] > k){
				ans += b[i];
				ans += 2*a[i];				
			}else{
				ans += a[i];
				ans += b[i]+k;
			}
		}
		for(int i = m+1; i <= n; ++i){
//			printf("[%d]\n", a[i]);
			ans += a[i];
		}
				
	}
	
	cout << ans;
	//scanf("%d", &ans);
	return 0;
}