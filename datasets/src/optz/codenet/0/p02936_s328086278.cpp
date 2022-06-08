#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#define N 2000005
#define NIL -1
using namespace std;

struct Node{
    long long l;
    long long r;
    long long s;
};

long n,q;

struct Node node[N];

void ope(long long p){ //pが親 cが足す値
    if (node[p].l!=NIL){
        node[node[p].l].s+=node[p].s;
        ope(node[p].l);
    }
    if (node[p].r!=NIL){
        node[node[p].r].s+=node[p].s;
        ope(node[p].r);
    }
}

int main(){
    cin>>n>>q;
    for (long long i=1; i<=n; i++){
        node[i].l=NIL;
        node[i].r=NIL;
        node[i].s=0;
    }
    for (long long i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        if (node[a].l==NIL) node[a].l=b;
        else node[a].r=b;
    }
    for (long i=0; i<q; i++){
        long a,b;
        cin>>a>>b;
        node[a].s+=b;
    }
    ope(1);
    for (long i=1; i<=n; i++) cout<<node[i].s<<endl;
}