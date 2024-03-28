#include <bits/stdc++.h>
using namespace std;
int n, m, t;//y, x
int mp[50][50];//y,x
int s_x, s_y, t_x, t_y;

int ans = 0;

int go[4][2] = {
	{1,0}, {-1,0},{0,1},{0,-1}
};

void pp(){
	for(int i = 0; i <= n+1; ++i){
		for(int j = 0; j <= m+1; ++j){
			printf("%d", mp[i][j]);
		}printf("\n");
	}	
}

void dfs(int x, int y){

	if(x == t_x && y == t_y){
		ans++;
		return;
	}
	mp[y][x] = 2;
//	printf("\n");
//	pp();
	for(int i = 0; i < 4; ++i){
		int n_x = x+go[i][0];
		int n_y = y+go[i][1];
		
		if(mp[n_y][n_x] == 0){
//			printf("to[%d %d]\n", n_x, n_y);
			dfs(n_x, n_y);
		}
	}
	mp[y][x] = 0;
	
}


int main(){
	cin >> n >> m >> t;
	cin >> s_x >> s_y >> t_x >> t_y;
	
	for(int i = 0; i <= n+1; ++i){
		mp[i][0] = 1;
		mp[i][m+1] = 1;
	}
	for(int i = 0; i <= m+1; ++i){
		mp[0][i] = 1;
		mp[n+1][i] = 1;
	}	
	
	for(int i = 0; i < t; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		mp[y][x] = 1;
	}
	

	
	dfs(s_x, s_y);
	
	cout << ans;
	
	
}