/**
 * @file P1618三连击（升级版）.cpp
 * @author luozi
 * @brief 洛谷提单#暴力枚举
 * @version 0.1
 * @date 2022-10-20
 * @link https://www.luogu.com.cn/problem/P1618
 * @copyright xX_luozi_Xx (c) 2022
 * 
 */

#include <algorithm>
#include <iostream>
using namespace std;
int str[10] = {1,2,3,4,5,6,7,8,9};
int A,B,C;
bool check(){
    int a = 0, b = 0, c = 0;
    a = str[0]*100+str[1]*10+str[2];
    b = str[3]*100+str[4]*10+str[5];
    c = str[6]*100+str[7]*10+str[8];

    if((A*b*c)==a*B*c&&a*B*c==a*b*C){
        return true;
    }else{
        return false;
    }
}
int main(){
    bool bad = 1;
    cin >> A >> B >> C;
    do{
        if(check()){
            printf("%d%d%d %d%d%d %d%d%d\n",str[0], str[1], str[2], str[3], str[4], str[5],str[6],str[7],str[8]);
            bad = 0;
        }
    }while(next_permutation(str, str+9));
    return bad?0*printf("No!!!"):0;
}