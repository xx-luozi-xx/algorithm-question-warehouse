#include <unordered_map>
#include <iostream>

using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cout.tie(0), cin.tie(0), 0);

unordered_map<string, string> un;

inline void creat(const string& str)noexcept{
    if(un.count(str) == 0){
        un[str] = str;
    }
}
const string& ufind(const string& str)noexcept{
    return un[str]==str?str: un[str]=ufind(un[str]);
}
inline void U(const string& son, const string& fa)noexcept{
    un[ufind(son)]=ufind(fa);
}

int main(){
    char op;
    string in;
    string fa;
    string son;
    for(cin >> op; op != '$'; cin >> op){
        cin >> in;
        creat(in);
        if(op == '#'){
            fa.swap(in);            
        }else if(op == '+'){
            son.swap(in);
            U(son, fa);
        }else if(op == '?'){
            cout << in << ' ' << ufind(in) << '\n';
        }
    }
    return 0;
}