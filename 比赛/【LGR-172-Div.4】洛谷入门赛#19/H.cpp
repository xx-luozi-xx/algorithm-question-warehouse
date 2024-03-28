#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX_SIZE = 2000+30;

string str;
string s1 = "Genshin";
string s2 = "player";

vector<int> p1, p2;
int main(){
    cin >> str;
    for(int i = 0; i < str.size(); ++i){
        int yes = 1;
        for(int j = 0; j < s1.size(); ++j){
            if(i+j >= str.size() or str[i+j] != s1[j]){
                yes = 0;
                break;
            }
        }
        if(yes){
            p1.push_back(i);
        }

        yes = 1;
        for(int j = 0; j < s2.size(); ++j){
            if(i+j >= str.size() or str[i+j] != s2[j]){
                yes = 0;
                break;
            }
        }
        if(yes){
            p2.push_back(i);
        }
    }

    long long ans = 0;
    for(int i = 0; i < p1.size(); ++i){
        int  l = 0, r = p2.size()-1;
        int j = -1;
        while(l <= r){
            int mid = (l+r)>>1;
            if(p1[i]+s1.size()-1 <= p2[mid]){
                j = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        if(j != -1){
            ans += p2.size()-j;
        }

        // for(int j = 0; j < p2.size(); ++j){
        //     if(p1[i]+s1.size()-1 <= p2[j]){
        //         ans++;
        //     }
        // }
    }
    cout << ans;
}