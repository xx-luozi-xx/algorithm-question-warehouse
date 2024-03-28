#include <iostream>

using namespace std;

int main() {
  int taskId;
  cin >> taskId;
  if (taskId == 1) {
    cout << "5 5 7 " <<endl;
  } else if (taskId == 2) {
    int T = 2e5;
    cout << T << '\n';
    for(int i = 1; i <= T; ++i){
        cout << "std::cerr\n";
    }
  }
  return 0;
}