#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
  	for(int i = 1; i <= n; ++i){
    	int a; cin >> a;
      	cout << a;
      	if(i != n){
        	cout << ',';
        }
    }
  	return 0;
}