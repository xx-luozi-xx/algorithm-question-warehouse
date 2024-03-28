#include <iostream>
#include <vector>
#include <string>
using namespace std;

int a[11] = {1,1,1,1,1,1,1,1,1,1,0};
void next(){
    a[0]++;
    for(int i = 0; i < 10; ++i){
        if(a[i]==4){
            a[i]=1,a[i+1]++;
        }else{
            return;
        }
    }
}
bool end(){
    return a[10];
}
int sum(){
    int sum = 0;
    for(int i = 0; i<10; sum+=a[i++]);
    return sum;
}
int main(){
    int n;scanf("%d",&n);
    if(n<10||30<n){
        printf("0");
        return 0;
    }else{
        int out = 0;
        vector<string> arr;
        while(!end()){
            if(sum()==n){
                string box;
                for(int i = 9; i>=0; --i){
                    box.push_back(a[i]+'0');
                    box.push_back(' ');
                }
                arr.push_back(box);
                out++;
            }
            next();
        }
        printf("%d\n",out);
        for(int i = 0; i<out; ++i){
            cout<<arr[i]<<endl;
        }
    }
    return 0;
}