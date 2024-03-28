#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	static const int MAX_SIZE = 1e4+30;
    int strStr(string haystack, string needle) {
		unordered_map<char, int> *dfa = new unordered_map<char, int>[MAX_SIZE];
		dfa[0][needle[0]] = 1;
		int X = 0;
		for(int i = 1; i < needle.size(); ++i){
			for(int j = 0; j < 128; ++j){
				if(needle[i] == j){
					dfa[i][j] = i+1;
				}else{
					dfa[i][j] = dfa[X][j];
				}
			}
			X = dfa[X][needle[i]];
		}
		int p = 0;
		for(int i = 0; i < haystack.size(); ++i){
			p = dfa[p][haystack[i]];
			if(p == needle.size()){
				return i-int(needle.size())+1;
			}
		}
		return -1;
    }
};

int main(){
	Solution s;
	cout << s.strStr("abc", "c");
}