#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>> n;
	for(int i = 1; i*i*i <= n; ++i){
		if(i*i*i == n){
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}