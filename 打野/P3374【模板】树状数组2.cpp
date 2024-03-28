#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_SIZE = 500000+30;

int data[MAX_SIZE];
int peter[MAX_SIZE];
int N, M;

inline int lb(int i)noexcept{
	return i&-i;
}
inline void add(int i, int num)noexcept{
	while(i < MAX_SIZE){
		peter[i]+=num;
		i+=lb(i);
	}
}
inline int sum(int i)noexcept{
	int ans = 0;
	while(i){
		ans+= peter[i];
		i^=lb(i);
	}
	return ans;
}


signed main(){
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= N; ++i){
		cin >> data[i];
	}
	for(int i = 1; i <= N; ++i){
		add(i, data[i]-data[i-1]);
	}

	for(int i = 1; i <= M; ++i){
		int op; cin >> op;
		if(op == 1){
			int x, y, k;
			cin >> x >> y >> k;
			add(x, k);
			add(y+1, -k);
		}else{
			int x; cin >> x;
			cout << sum(x) << '\n';
		}
	}
	return 0;
}