#include <bits/stdc++.h>
#define NIL -1
#define MAX 200000

typedef long long int ll;
using namespace std;

struct Node{
    int p,l,r,v;
};
Node gNode[MAX];

//子供or兄弟がいれば自分と子供・兄弟にx足す関数を作ればよさげ
void add_value(int n,int node,int x){
    //自分に足す
    gNode[node].v+=x;
    if(gNode[node].l!=NIL){
        //子供にx足す
        add_value(n+1,gNode[node].l,x);
    }
    if(n>0){
    if(gNode[node].r!=NIL){
        //兄弟にx足す
        add_value(n+1,gNode[node].r,x);
    }
    }
    return;
}

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int N,Q;
cin>>N>>Q;

//Node gNode[N];
for(int i=0;i<N;i++){
    gNode[i].p=NIL;
    gNode[i].l=NIL;
    gNode[i].r=NIL;
    gNode[i].v=0;
}
//代入
int a,b;    
for(int i=0;i<N-1;i++){
    cin>>a>>b;
    a=a-1;
    b=b-1;

    if(gNode[a].l==NIL){
        gNode[a].l=b;
    }
    else{
        int idx=gNode[a].l;
        while(gNode[idx].r!=NIL){
            idx=gNode[idx].r;
        }
        gNode[idx].r=b;
    }
    gNode[b].p=a;
}

//操作
int p,x;
for(int i=0;i<Q;i++){
    cin>>p>>x;
    p=p-1;
    //各々が自分の子供全員にx足していけばok?
    add_value(0,p,x);
}
for(int i=0;i<N;i++){
    cout<<gNode[i].v<<" ";
}
cout<<endl;
//system("pause");
return 0;
}