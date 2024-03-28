    #include <bits/stdc++.h>
    using namespace std;
    #define MAX_SIZE (int(1e5 +30))
    int M, N;
    int data[MAX_SIZE];

    bool check(long long x){
        long long sum = data[0];
        int cnt = 1;
        for(int i = 1; i < N; ++i){
            if(sum+data[i]<=x){
                sum+=data[i];
            }else{//over
                cnt++;
                sum = data[i];
            }
        }
        return cnt <= M;
    }

    int main(){
        cin >> N >> M;
        long long _max = 0, _min = 0;
        for(int i = 0; i < N; ++i){
            scanf("%d", data+i);
            _max += data[i];
            _min = max((long long)(data[i]), _min);
        }
        long long ans;
        while(_min<=_max){
            long long mid = (_max+_min)>>1;
            if(check(mid)){
                ans = mid;
                _max = mid-1;
            }else{
                _min = mid+1;
            }
        }
        cout << ans;
        return 0;
    }
