#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define lli long long int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q,i,j;
	cin>>n>>q;
	vector<vector<int> > adj;
	adj.resize(n);
	lli a,b;
	for(i=0;i<n-1;i++)
	{
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	vector<lli> val;
	val.resize(n);
	for(i=0;i<q;i++)
	{
		cin>>a>>b;
		val[a-1] += b; 
	}
	vector<int> par;
	par.resize(n);
	for(i=0;i<n;i++)
		par[i] = -1;
	par[0] = 0;
	queue<int> q1;
	q1.push(0);
	while(!q1.empty())
	{
		int x = q1.front();
		q1.pop();
		for(i=0;i<adj[x].size();i++)
		{
			int y = adj[x][i];
			if(par[y]==-1)
			{
				par[y] = x;
				val[y] += val[x];
				q1.push(y);
			}
		}
	}
	for(i=0;i<n;i++)
		cout<<val[i]<<" ";
	cout<<endl;
	return 0;
}