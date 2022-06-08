#include<bits/stdc++.h>
using namespace std;
const int ms = 10;
int visit[ms];
vector<int> g[ms];
int n,m;

int dfs(int node, int p){
	visit[node] = 1;
	bool f = 0;
  for(int i = 1;i<=n;i++){
  	if(!visit[i])
      	f = 1;
  }
  if(!f)
    	return 1;
 	int ans = 0;
  for(auto it : g[node]){
  		if(it==p)
          	continue;
   		if(!visit[it]){
        	ans+=dfs(it,node);
          visit[it] = 0;
        }
  
  }
  return ans;
  

}

int main(){
	int a,b;
	cin >> n >> m;
  for(int i = 0;i<m;i++){
  	cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout<<dfs(1,-1);

}
