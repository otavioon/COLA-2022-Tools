#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;
 
#define f first
#define s second
 
#define pb push_back
#define pp pop_back
#define mp make_pair
 
#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()
#define clr(a,v) memset(a, v, sizeof(a))
 
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, l, r) for (int i = (l); i >= (r); i--)
#define reflex ios_base::sync_with_stdio(false)
 
#define nl '\n'
#define ioi exit(0);
 
 
#define PI 3.14159265
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N= (int)2e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
//const int mod = 1000000007;
const ll linf = (ll)1e18 + 7;
const ll limit = 2e9;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int kx[] = {-1,1,2,2,1,-1,-2,-2};
const int ky[] = {2,2,1,-1,-2,-2,-1,1};
 
//const int mod = 998244353;
 
struct dsu{
	int parent[N];
	int cont;
	void make_set(int n){
		for(int i = 1; i <= n; i++)
			parent[i] = i;
		cont = n;
	}
	
	int find_set(int v){
		if(v == parent[v])
			return v;
		return find_set(parent[v]);
	}
	
	void union_sets(int a, int b){
		a = find_set(a);
		b = find_set(b);	
		if(a != b){
			parent[b] = a;
			cont--;
		}
	}
};


bool vis[107][107];
int dis[107][107];

struct nod{
	int x, y, d;
	nod(int x_, int y_, int d_){
		x = x_;
		y = y_;
		d = d_;
	}
};

bool ok(int x, int y, int n, int m){
	return 0 <= x && x < n && 0 <= y && y < m;
}

int shortestPathBinaryMatrix(vector<vector<int>>& g) {
	clr(dis,0);
	int n = (int)g.size();
	int m = (int)g[0].size();
	
	queue<nod> q;
	q.push(nod(0,0,1));
	vis[0][0] = true;
	dis[0][0] = 1;
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().d;
		q.pop();
		for(int k = 0; k < 8; k++){
			int a = x + dx[k];
			int b = y + dy[k];
			if(ok(a,b,n,m) && !vis[a][b] && g[a][b] == 0){
				vis[a][b] = true;
				dis[a][b] = d + 1;
				q.push(nod(a,b,d+1));
			}
		}
	}
	if(dis[n-1][n-1] != 0)
		return dis[n-1][n-1];
    return -1;
}
    
int main()
{	
	
	
	int n, x; cin>> n>> x;
	if(n*500 >= x)
		cout<<"yes";
	else
		cout<<"no";
	
	return 0;
}
