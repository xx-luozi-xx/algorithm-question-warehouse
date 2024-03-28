#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
struct eage{
    int v1;
    int v2;
    unsigned int weight;
    int next = 0;
    bool operator < (const eage& rhs){return weight < rhs.weight;};
    bool operator()(const eage& lhs, const eage& rhs){ return lhs.weight > rhs.weight;}
};

struct node{
    int v;
    unsigned weight;
    bool operator()(const node& lhs, const node& rhs){return lhs.weight > rhs.weight;}
};

int adj[100000+5]{};//某顶点的邻接链表的头，顶点号从1开始
eage graph[5*100000+5]{};//! 0的位置不存，作为尾标记
int graph_size = 0;

unsigned shortest[100000+5]{};//最短路长
bool v_set[100000+5]{};

int main(){
    int n, m ,s;
    scanf("%d %d %d", &n, &m, &s);
    //*存图
    for(int i = 0; i < m; ++i){ 
        eage input;
        scanf("%d %d %d", &input.v1, &input.v2, &input.weight);
        input.next = adj[input.v1];//当前节点连上上一个
        graph[++graph_size] = input;//节点往里装
        adj[input.v1] = graph_size;//头节点移动
/*
        swap(input.v1, input.v2);
        input.next = adj[input.v1];//当前节点连上上一个
        graph[++graph_size] = input;//节点往里装
        adj[input.v1] = graph_size;//头节点移动*/
    }
    //* 以s为起点 初始化
    memset(shortest, -1, sizeof(shortest));
    priority_queue<node, vector<node>, node> min_weight;
    shortest[s] = 0;
    min_weight.push((node){s, 0});

    while(!min_weight.empty()){//保证n个点都达到过(第一个个点初始化已经加入)
        node min = min_weight.top();
        min_weight.pop();
        if(v_set[min.v] == false){
            v_set[min.v] = true;
            for(int i = adj[min.v]; i!=0; i = graph[i].next){//todo v2所有邻接都加入
                //! 同时更新标号                    
                shortest[graph[i].v2] = std::min(shortest[graph[i].v2], shortest[min.v]+graph[i].weight);
                if(v_set[graph[i].v2] == false){//目标点没到过，直接加
                    min_weight.push((node){graph[i].v2, shortest[graph[i].v2]});
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        shortest[i]!=unsigned(-1)?printf("%d ",shortest[i]):printf("%d ",0x7fffffff);
    }
    return 0;
}