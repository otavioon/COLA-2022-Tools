// When you are hungry for something and you're determined and you're focused 
// and you're committed to something it's hard to surrender, isn't it?

#include<bits/stdc++.h>
using namespace std;

#define all(x)                  (x).begin(), (x).end()
#define endl                    "\n"
#define ll                      long long 
#define int                     ll
#define mod                     1000000007
#define setbit(x)               __builtin_popcount(x)
#define fff(i,n)                for(int i=0;i<n;i++)
#define fab(i,a,b)              for(int i=(a);i<(b);i++)
#define ff                      first
#define ss                      second
#define pb                      push_back
#define vi                      vector<int>
#define pii                     pair<int,int>
#define clrgra                  for(auto& i:gra) i.clear();
#define clrvis                  memset(vis,0,sizeof(vis));
#define clrdis                  memset(dis,-1,sizeof(dis));
#define fio                     ios_base::sync_with_stdio(false); cin.tie(NULL);

const long double eps = 1.0e-14;      // allowable error 

ll fac[10000001]; 
void fact(){
    fac[0]=1;
    for(int i=1;i<=10000000;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    return ;
}

ll prime[400005];
void sieve(){
    prime[0]=0;
    prime[1]=0;
    for(int i=2;i<400005;i++){
        prime[i]=1;
    }
    for(int i=2;i*i<400005;i++){
        if(prime[i]==1){
            for(int j=i*i;j<400005;j+=i){
                prime[j]=0;
            }
        }
    }
    
}
 
ll power(ll n , ll p ){
    if(p==0)
        return 1;
    
    ll res = power((n*n)%mod,p/2);
    if(p%2==1)
        res = (n*res)%mod;
    
    return res;
}
 
ll bit[100005]; 
void upd(ll i,ll val,ll n) {
    for(;i<=n;i+=i&(-i))
        bit[i]+=val;
}
 
ll qry(ll i) {
    ll sum=0;
    for(;i>0;i-=i&(-i))
        sum+=bit[i];
    return sum;
}
 
ll pa[500005]; 
ll fin(ll u) {
    if(pa[u]==u)
        return u;
    return fin(pa[u]);
}

ll si[500005]; 
void uni(ll u,ll v) {
    ll p1=fin(u);
    ll p2=fin(v);
    if(p1==p2)
        return;
    if(si[p1]<si[p2])
        swap(p1,p2);
    si[p1]+=si[p2];
    pa[p2]=p1;
    return;
}

int log(int x) {
    int i;
    for(i=0;(1<<i)<=x;i++);
    return i;
}

vector<int> osci(vector<int> v) {
	vector<int> v1;
	int n=v.size();
	int i=0,j=n-1;
	for(int k=0;k<n;k++) {
		if(k%2==0)
			v1.pb(v[i++]);
		else
			v1.pb(v[j--]);
	}
	reverse(all(v1));
	return v1;
} 

vi gra[100005];
int dis[100005];
int vis[100005];

void dfs(int v) {
    vis[v]=0;
    //dis[v]=q;
    for(auto i:gra[v]) {
        if(vis[i]==0) {
            dfs(i);
        }
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    vis[v]=1;
    dis[v]=0;
    
    while(!q.empty()) {
        int curr=q.front();
        q.pop();
        for(auto i:gra[curr]) {
            if(vis[i]==0) {
                q.push(i);
                dis[i]=dis[curr]+1;
                vis[i]=1;
            }
        }
    }
}

 
int32_t main() {
    fio
	cout << fixed << setprecision(15);
    
    int n;cin >> n;
    
    fff(i,n) {
        int a;cin >> a;
        gra[i+1].pb(a);
        //gra[a].pb(i+1);
    }
    
    bfs(1);
    
    if(vis[2]==0)
    cout << -1;
    else
    cout << dis[2];
    
    
    return 0;
    
}