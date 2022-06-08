#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

int visited[200001] ;
int final[200001] ;

void dfs(vector<vector<int>> &adj, int source){


	visited[source]=1 ;

	//cout<<source<<"\n" ;

	for(auto x:adj[source])
		{
		//	cout<<x<<"\n" ;
				
				if(visited[x]==0){		
					final[x]+=final[source] ;
					visited[x]=1 ;
					dfs(adj,x) ;
			}
		}
	
}


void solve(){

	int v,q ;
	cin>>v>>q ;

	vector<vector<int>> adj(v+1) ; 

	rep(i,v-1){
		int x,y ;
		cin>>x>>y ;
		x-- ;
		y-- ;

		adj[x].push_back(y) ;

	}

	/*
	rep(i,v){

		cout<<i<<"----->" ;
		for(auto x:adj[i]){
			cout<<x<<" " ;
		}
		cout<<"\n" ;
	}
	*/

	memset(final,0,sizeof(final)) ;
	memset(visited,0,sizeof(visited)) ;

	rep(i,q){
		int n,x ;
		cin>>n>>x ;
		n-- ;
		final[n]+=x ;

	}

	dfs(adj,0) ;


	rep(i,v){
		cout<<final[i]<<"\n" ;
	}
	
}

int main(){
	
	int y ;

	y=1 ;
	//cin>>y ;

	while(y--)
	{	
		solve() ;
	}

}