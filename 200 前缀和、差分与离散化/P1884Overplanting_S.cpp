#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int MAX_SIZE = 4000+30;

int N;
struct Rectangle{
    int x1, y1, x2, y2;
}rectangle[MAX_SIZE];

int num[MAX_SIZE];
int num_size = 0;

unordered_map<int, int> to_me;
unordered_map<int, int> back_me;

int plain[MAX_SIZE][MAX_SIZE];
int real[MAX_SIZE][MAX_SIZE];

int main(){
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> rectangle[i].x1
            >> rectangle[i].y1
            >> rectangle[i].x2
            >> rectangle[i].y2;
        num[num_size++] = rectangle[i].x1;
        num[num_size++] = rectangle[i].y1;
        num[num_size++] = rectangle[i].x2;
        num[num_size++] = rectangle[i].y2;
    }
    num[num_size++] = __INT_MAX__;
    sort(num, num+num_size);
    num_size = unique(num, num+num_size) - num;
    for(int i = 0; i < num_size; ++i){
        to_me.insert({num[i], i+1});
        back_me.insert({i+1, num[i]});
    }
    for(int i = 0; i < N; ++i){
        rectangle[i].x1 = to_me[rectangle[i].x1];
        rectangle[i].y1 = to_me[rectangle[i].y1];
        rectangle[i].x2 = to_me[rectangle[i].x2];
        rectangle[i].y2 = to_me[rectangle[i].y2];  
    }
    for(int i = 0; i < N; ++i){
        int x1 = min(rectangle[i].x1, rectangle[i].x2);
        int y1 = min(rectangle[i].y1, rectangle[i].y2);
        int x2 = max(rectangle[i].x1, rectangle[i].x2);
        int y2 = max(rectangle[i].y1, rectangle[i].y2);

        plain[x1][y1]++;
        plain[x1][y2]--;
        plain[x2][y1]--;
        plain[x2][y2]++;
    }

    for(int i = 1; i < num_size+1; ++i){
        for(int j = 1; j < num_size+1; ++j){
            real[i][j] = plain[i][j] + real[i-1][j] + real[i][j-1] - real[i-1][j-1];
        }
    }
    unsigned long long ans = 0;
    for(int i = 1; i < num_size+1; ++i){
        for(int j = 1; j < num_size+1; ++j){
            ans += (long long)(!!real[i][j])*(back_me[i+1]-back_me[i])*(back_me[j+1]-back_me[j]);
        }
    }
    cout << ans;
    return 0;
}
