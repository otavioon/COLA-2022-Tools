#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,vector<bool> > P;
typedef long long int ll;


struct Edge{int to;};
vector<Edge> G[10];

int N,M;
int cnt=0;

bool check(vector<bool>& used){
	for(int i=1;i<=N;i++){
		if(!used[i]) return false;
	}
	return true;
}

void solve(int v, vector<bool>& used){

	//cout<<"["<<v<<"]";
	//for(int i=1;i<=N;i++) 
	//	cout<<used[i]<<" ";


	if(check(used)){
		cnt++;
		return;
	}

	for(int i=0;i<G[v].size();i++){
		int u=G[v][i].to;
		if(used[u]) continue;
		vector<bool> us(used);
		us[u]=true;
		//cout<<"->"<<u<<endl;
		solve(u, us);
	}

}

int main(){

	cin>>N>>M;
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		Edge e1,e2;
		e1.to = b; e2.to = a;
		G[a].push_back(e1);
		G[b].push_back(e2);
	}
	vector<bool> used(N+1);
	fill(used.begin(),used.end(),false);
	used[0]=true; used[1]=true;

	solve(1,used);
	cout<<cnt<<endl;
	return 0;
}

