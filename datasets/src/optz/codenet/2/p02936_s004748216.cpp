#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = (long long)1e9 + 7; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}


void solve(vector<vector<int>> &tree, vector<int> &count, vector<int> &ans, int per, int node, int sum){
	
	ans[node] = sum + count[node];
	
	for(int i = 0; i < tree[node].size(); i++){
		if(tree[node][i] == per) continue;
		solve(tree, count, ans, node, tree[node][i], sum + count[node]);
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	vector<vector<int>> tree;
	vector<int> count, ans;
	int N, Q;
	int a, b, p, x;
	
	cin>>N>>Q;
	
	tree.resize(N+2);
	count.resize(N+2);
	ans.resize(N+2);
	
	for(int i = 1; i < N; i++){
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	for(int i = 0; i < Q; i++){
		cin>>p>>x;
		
		count[p] += x;
	}
	
	solve(tree, count, ans, 0, 1, 0);
	
	for(int i = 0; i < N; i++){
		if(i) cout<<" ";
		cout<<ans[i+1];
	}
	cout<<endl;
	return 0;
}