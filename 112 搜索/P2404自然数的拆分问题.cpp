#include <stdio.h>
int bag[100];
int bag_size = 0;

void split(int num, int m_){// {split(num) >= m_}
    if(num == 1) {//递归到1是一个答案，输出
        bag[bag_size++] = 1;
        for(int i = 0; i < bag_size; ++i){
            printf("%d%s", bag[i], i==bag_size-1?"":"+");
        }printf("\n");
        bag_size--;
        return;
    }
    //一个数分两半, 前面小于等于后面，前面大于等于m_
    for(int i = 1; i <= num-i; ++i){
        if(i >= m_){
            bag[bag_size++] = i;
            split(num-i, i);
            bag_size--;
        }
    }
    if(bag_size > 0){//自己被分完了，自己就不分了，作为答案
        bag[bag_size++] = num;
        for(int i = 0; i < bag_size; ++i){
            printf("%d%s", bag[i], i==bag_size-1?"":"+");
        }printf("\n");
        bag_size--;
    }
    return;
}


int main(){
    int n;
    scanf("%d", &n);
    split(n, 1);
    return 0;
}