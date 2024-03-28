#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
  	for(int i = 1; i <= n; ++i){
    	int a; cin >> a;
    	if(a == 1){
        	cout << i;
          	return 0;
        }
    }
}