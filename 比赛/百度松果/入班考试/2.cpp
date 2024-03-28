#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    sort(str.begin(), str.end());
    cout << str.back();
}