#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 1e4+30;
int dp_A[MAX_SIZE];
int dp_B[MAX_SIZE];

int main(){
    int n; cin >> n;
    while(n--){
        string str; cin >> str;
        if(str[0] == 'A'){
            dp_A[0] = 0;
            dp_B[0] = 1;
        }else{
            dp_A[0] = 1;
            dp_B[0] = 0;
        }

        for(int i = 1; i < str.size(); ++i){
            if(str[i] == 'A'){
                dp_A[i] = dp_B[i-1];
                dp_B[i] = dp_A[i-1]+1;
            }else{
                dp_A[i] = dp_B[i-1]+1;
                dp_B[i] = dp_A[i-1];          
            }
        }
        cout << min(dp_A[str.size()-1], dp_B[str.size()-1]) << '\n';
    }
    return 0;
}
