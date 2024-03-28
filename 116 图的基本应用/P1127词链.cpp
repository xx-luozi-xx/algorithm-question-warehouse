#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 200;
const int MAX_M = 1000+30;

int m;
map<string, int> all_eage;
set<pair<string, int>> eage[MAX_N];
int d_in[MAX_N];
int d_out[MAX_N];
unordered_set<int> point;
set<int> point_src;
inline void eage_add(int a, int b, const string& str)noexcept{
    eage[a].insert({str,b});
    d_out[a]++;
    d_in[b]++;
    point.insert(a);
    point.insert(b);
    
    point_src.insert(a);

    all_eage[str]++;
}

void islinked_dfs(int now, unordered_set<int>& st)noexcept{
    if(st.count(now)) return;
    st.insert(now);
    for(auto itr = eage[now].begin(); itr != eage[now].end(); ++itr){
        islinked_dfs(itr->second, st);
    }
}

inline unordered_set<int> islinked(int src)noexcept{
    unordered_set<int> ret;
    islinked_dfs(src, ret);
    return ret;
}

vector<string> ans;
void find_path(int now)noexcept{
    if(ans.size() == m){
        for(int i = 0; i < ans.size(); ++i){
            cout << ans[i];
            if(i != ans.size()-1){
                cout << '.';
            }
        }
        exit(0);
    }

    for(auto itr = eage[now].begin(); itr != eage[now].end(); ++itr){
        if(all_eage[itr->first]){
            all_eage[itr->first]--;
            ans.push_back(itr->first);
            find_path(itr->second);
            ans.pop_back();
            all_eage[itr->first]++;
        }
    }
}

int main(){
    cin >> m;
    for(int i = 1; i <= m; ++i){
        string in; cin >> in;
        eage_add(*in.begin(), *in.rbegin(), in);
    }
    //联通判定
    bool linked = 0;
    for(auto itr = point.begin(); itr != point.end(); ++itr){
        if(point == islinked(*itr)){
            linked = 1;
            break;
        }
    }

    if(linked == 0){
        cout << "***";
        return 0;
    }

    //欧拉路判定
    int src = 0;
    int des = 0;
    for(int i = 'a'; i <= 'z'; ++i){
        if(d_in[i] == d_out[i]){
            continue;
        }else if(d_in[i] - d_out[i] == 1){
            if(des){
                cout << "***";
                return 0;
            }else{
                des = i;
            }
        }else if(d_out[i] - d_in[i] == 1){
            if(src){
                cout << "***";
                return 0;
            }else{
                src = i;
            }
        }else{
            cout << "***";
            return 0;
        }
    }

    if(src == 0){
        src = *point_src.begin();
    }

    //开找
    find_path(src); 
}
