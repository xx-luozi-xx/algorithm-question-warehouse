#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int MAX_SIZE = 5e3+30;

int n, m;
struct Interval{
    int l, r, odd;
    int l_1;
}interval[MAX_SIZE];

int num[MAX_SIZE*2*2];
int num_size = 0;

int un[MAX_SIZE*2*2*2];
int un_init(){
    for(int i = 0; i < MAX_SIZE*2*2*2; ++i){
        un[i] = i;
    }
    return 0;
}
int un_init_ = un_init();

int ufind(int x){
    return x==un[x]?x:x=ufind(un[x]);
}
void uunion(int x, int y){
    un[ufind(x)] = ufind(y);
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        string str;
        cin >> interval[i].l >> interval[i].r >> str;
        interval[i].odd = (str=="odd");
        num[num_size ++] = interval[i].l;
        num[num_size ++] = interval[i].l-1;
        num[num_size ++] = interval[i].r;
    }
    sort(num, num+num_size);
    num_size = unique(num, num+num_size)-num;
    for(int i = 0; i < m; ++i){
        interval[i].l_1 = lower_bound(num, num+num_size, interval[i].l-1)-num+1;
        interval[i].l = lower_bound(num, num+num_size, interval[i].l)-num+1;
        interval[i].r = lower_bound(num, num+num_size, interval[i].r)-num+1;
    }

    for(int i = 0; i < m; ++i){
        if(interval[i].odd){
            if(ufind(interval[i].l_1) == ufind(interval[i].r) or
               ufind(interval[i].l_1 + num_size) == ufind(interval[i].r + num_size)){
                cout << i; 
                return 0;
            }else{
                uunion(interval[i].l_1, interval[i].r + num_size);
                uunion(interval[i].l_1 + num_size, interval[i].r);
            }
        }else{
            if(ufind(interval[i].l_1) == ufind(interval[i].r + num_size) or
               ufind(interval[i].l_1 + num_size) == ufind(interval[i].r)){
                cout << i; 
                return 0;
            }else{
                uunion(interval[i].l_1, interval[i].r);
                uunion(interval[i].l_1 + num_size, interval[i].r + num_size);
            }
        }
    }
    cout << m;
    return 0;
}