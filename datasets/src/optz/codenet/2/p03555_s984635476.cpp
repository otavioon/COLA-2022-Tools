#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

#define MAX_V 200000

long long int INF = 100000000000000000LL;

struct edge{
    int to;
    long long int cost;
};

typedef pair<long long int, int> P; // firstは最短距離、secondは頂点の番号

vector<edge> G[MAX_V];
long long int d[MAX_V];

// 速さはO(|E|log|V|)

void printGraph(int n, const vector<edge>* g) {
    printf("----------PrintGraph---------\n");
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0U; j < g[i].size(); ++j) {
            printf("G[%d][%zu] : to = %d, cost = %lld", i, j, g[i][j].to, g[i][j].cost);
            printf("\n");
        }
    }
    printf("----------PrintGraph---------\n");
}

void printEdge(int v, int i,const edge& e) {
    printf("----------PrintEdge---------\n");
    printf("G[%d][%d].e : to = %d, cost = %lld\n", v, i, e.to, e.cost);
    printf("----------PrintEdge---------\n");
}

void printIf(long long a, long long b, int eTo, long long cost, int v) {
    printf("----------PrintIf-----------\n");
    printf("e.to = %d\n", eTo);
    printf("e.cost = %lld\n", cost);
    printf("From : d[%d] = %lld\n", v, b);
    printf("To   : d[%d] = %lld\n", eTo, a);
    printf("d[e.to] > e.cost + d[v] , %lld > %lld + %lld = %d\n", a, cost, b, a > cost + b);
    printf("----------PrintIf-----------\n");
}

void printDist(long long* d, size_t size) {
    printf("----------PrintDist---------\n");
    for (size_t i = 0; i < size; ++i) {
        printf("d[%zu] = %lld\n", i, d[i]);
    }
    printf("----------PrintDist---------\n");
}

void printQueue(priority_queue<P, vector<P>, greater<P>> q) {
    printf("----------PrintQueue---------\n");
    size_t size = q.size();
    for (size_t i = 0; i < size; ++i) {
        printf("q[%zu] : first = %lld, second = %d\n", i, q.top().first, q.top().second);
        q.pop();
    }
    printf("----------PrintQueue---------\n");
}

void printSwap(int eTo, long long cost, int v) {
    printf("----------PrintSwap----------\n");
    printf("d[e.to] = e.cost + d[v] , d[%d] = e.cost + d[%d] , d[%d] = %lld + %lld\n", eTo, v, eTo, cost, d[v]);
    printf("----------PrintSwap----------\n");
}

void shortest_path(int s, int V){ // Vは頂点数
    
    //priority_queue<P, vector<P>, greater<P> > que;
    
    queue<P> que;
    
    for(int i = 0; i < V; i++){
        d[i] = INF;
    }
    d[s] = 0;
    
    que.push(P(0, s));
    
    while(!que.empty()){
        
        printDist(d, V);
        
        P p = que.front();
        que.pop();
        
        int v = p.second;
        
        if(d[v] < p.first){
            continue;
        }
        
        for(int i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            printEdge(v, i, e);
            printIf(d[e.to], d[v], e.to, e.cost, v);
            if(d[e.to] > e.cost + d[v]){
                d[e.to] = d[v] + e.cost;
                printSwap(e.to, e.cost, v);
                que.push(P(d[e.to], e.to));
            }
            //printQueue(que);
        } // 頂点への最小コストを更新
    }
}

int main(){
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        edge e;
        e.to = i + 1;
        e.cost = 1;
        G[i].push_back(e);
    }
    
    printGraph(N, G);
    
    for(int i = 1; i < N; i++){
        edge e;
        e.to = (i * 10) % N;
        if(e.to == 0){
            e.to = N;
        }
        e.cost = 0;
        G[i].push_back(e);
    }
    
    printGraph(N, G);
    
    shortest_path(0, N + 1);
    
    cout << d[N] << endl;
    
    return 0;
}








