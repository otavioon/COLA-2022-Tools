#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define all(n) (n).begin(),(n).end()
typedef long long ll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}else{return 0;}}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}else{return 0;}}
template <class T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <class T> inline T LCM(T a,T b){return a*b/GCD(a,b);}

ll n,q;
ll a[200010],b[200010];
ll v[200010];
bool reached[200010]={0};
vector<ll> g[200010];

void dfs(ll s){
	reached[s]=1;
	FOR(i,g[s].size()){
		if(!reached[g[s][i]]){
			v[g[s][i]]+=v[s];
			dfs(g[s][i]);
		}
	}
}

int main(){
	
	cin >> n >> q;
	
	FOR(i,n-1){
		cin >> a[i] >> b[i];
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}

	
	FOR(i,200005){
		v[i]=0;
		
	}
	ll p,x;
	FOR(i,q){
		cin >> p >> x;
		v[p]+=x;
	}
	dfs(1);
	FOR(i,n){
		cout << v[i+1] << " ";
	}
	cout << endl;

}
