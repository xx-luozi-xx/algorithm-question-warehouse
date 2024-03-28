#include <bits/stdc++.h>
using namespace std;

string src;
string tar;

vector<string> tran;
vector<string> to;

set<string> vit;

int main(){
    cin >> src >> tar;
    string tmp;
    while(cin >> tmp){
        //if(tmp == "EOF") break;
        tran.push_back(tmp);
        cin >> tmp;
        to.push_back(tmp);
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>
    que;

    que.push({0, src});

    while(!que.empty()){
        string now = que.top().second;
        int step = que.top().first;
        que.pop();

        if(step > 10){
            printf("NO ANSWER!");
            return 0;
        }
        if(now == tar){
            cout << step;
            return 0;
        }
        if(vit.count(now)) continue;

        vit.insert(now);
        //printf("[%s]\n", now.c_str());
        for(int i = 0; i < now.size(); ++i){
            for(int j = 0; j < tran.size(); ++j){
                int L = tran[j].size();
                string sb = now.substr(i, L);
                //printf("<(%s),(%s)>\n", tran[j].c_str(), sb.c_str());
                if(sb == tran[j]){
                    string nxt = now.substr(0, i);
                    nxt += to[j];
                    nxt += now.substr(i+L);
                    que.push({step+1, nxt});
                    //printf("{%s}\n", nxt.c_str());
                }
            }
        }
    }

    printf("NO ANSWER!");
    return 0;
}