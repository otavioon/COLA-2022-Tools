#include<iostream>
#include<vector>
#include<stack>
using namespace std;

using  Graph=vector<vector<int>> ;


int main()
{
 int N,Q; cin >> N >> Q;
 Graph G(N);
 for(int i=0;i<N-1;i++){
     int a,b; cin >> a >> b;
     a-=1;
     b-=1;
     G[a].push_back(b);
     G[b].push_back(a);
 }
 vector<long> counter;
 vector<bool> seen;
 vector<int> par;
 vector<int> order;

 seen.assign(N,false);
 seen[0]=true;
 par.assign(N,-1);
 order.assign(N,0);
 counter.assign(N,0);

 stack<int> s;
 s.push(0);
 seen[0]=true;
 int cur=0;
 while(s.size()!=0){
     int u=s.top();
     s.pop();
     order[cur]=u;
     cur++;
     for(auto v:G[u]){
         if(seen[v])continue;
         seen[v]=true;
         s.push(v);
         par[v]=u;
     }
 }

 for(int i=0;i<Q;i++){
     int u,x; cin >> u >> x;
     counter[u-1]+=x;
 }
 for(int i=0;i<order.size();i++){
     if (order[i]==0){
         continue;
     }
     else{
         int u=order[i];
         counter[u]+=counter[par[u]];
     }
 }
 for(int i=0;i<N;i++){
     cout << counter[i] << ' ';
 }
 return 0;
}