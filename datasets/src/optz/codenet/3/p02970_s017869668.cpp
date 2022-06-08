#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <queue>
#define inp(X) cin >> X
#define out(X) cout << X << endl
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define MAX(A) *max_element(A.begin(),A.end())
#define MIN(A) *min_element(A.begin(),A.end())
#define SORT(A) sort(A.begin(),A.end())
using namespace std;

typedef long long int ll;
#define MOD 1000000007
#define INF 1000000001

ll gcd(ll x, ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}

bool bfs(vector<vector<int>> g, vector<int> &dist, int sv)
{
	queue<int> q;
	q.push(sv);
	dist[sv]=0;
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(auto v : g[now]){
			if(dist[v]!=-1) continue;
			dist[v] = dist[now]+1;
			q.push(v);
		}
	}
}

int main(void) {
	int n,d; cin >> n >> d;
	int ans = (n+(2*d+1)-1)/(2*d+1);
	out(ans);
}


