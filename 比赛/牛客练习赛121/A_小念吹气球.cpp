#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 2e5+30;

char str[MAX_SIZE];
int str_size = 0;

int main(){
    int n;
    cin >> n;
    cin >> str;
    sort(str, str+n);
    str_size = unique(str, str+n)-str;
    cout << n + str_size;
    return 0;
}