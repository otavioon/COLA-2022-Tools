#include<bits/stdc++.h>
using namespace std;
map<string, int> trad;
int z;
string inv_trad[200];
int add(string &s){
	if(trad.count(s)){
		return trad[s];
	}
	trad[s]=z;
	inv_trad[z]=s;
	return z++;
} 
bool vis[201];
vector<int> adj[201];
void dfs(int u){
	if(vis[u]) return;
	vis[u]=true;
	for (int v : adj[u]){
		dfs(v);
	}
}
void process(int u){
	memset(vis,false,sizeof vis);
	dfs(u);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		string a,b;
		cin>>a>>b>>b>>b>>b;
		int u=add(a);
		int v=add(b);
		process(u);
		if(vis[v]){
			cout<<"Fact"<<endl;
		}else{
			process(v);
			if(vis[u]){
				cout<<"Alternative Fact"<<endl;
			}else{
				cout<<"Pants on Fire"<<endl;
			}
		}
		return 0;
	}
}

