#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#define N 2000005
#define NIL -1
using namespace std;

struct Node{
    long l;
    long r;
    long long s;
};

long n,q;

struct Node node[N];

void ope(long p, long c){ //pが親 cが足す値
    if (node[p].l!=NIL){
        node[node[p].l].s+=c;
        ope(node[p].l,c);
    }
    if (node[p].r!=NIL){
        node[node[p].r].s+=c;
        ope(node[p].r,c);
    }
}

int main(){
    cin>>n>>q;
    for (int i=1; i<=n; i++){
        node[i].l=NIL;
        node[i].r=NIL;
        node[i].s=0;
    }
    for (int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        if (node[a].l==NIL) node[a].l=b;
        else node[a].r=b;
    }
    for (int i=0; i<q; i++){
        long a,b;
        cin>>a>>b;
        node[a].s+=b;
        ope(a,b);
    }
    for (int i=1; i<=n; i++) cout<<node[i].s<<endl;
}