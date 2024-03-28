#include <iostream>
#define int long long
using namespace std;

int A, B, C, D, E, F, G;
int P;
inline int f(int x, int y){
    return (A*x*x*x+
           B*y*y*y+
           C*x*x*y+
           D*x*y*y+
           E*x*y+
           F*x+
           G*y)%P;
}

signed main(){
    int X1, X2, Y1, Y2;
    cin >> A >> B >>  C >> D >> E >> F >> G;
    cin >> P;
    cin >> X1 >> X2 >> Y1 >> Y2;
    int ans = -0x3f3f3f3f;
    for(int x = X1; x <= X2; ++x){
        for(int y = Y1; y <= Y2; ++y){
            ans = max(ans, f(x, y));
        }
    }
    cout << ans;
}