#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define inf (ll)2147483647
#define mod (ll)(1e9+7)
#define d(x) cerr<<#x<<"="<<x<<endl;
#define p(x) cout<<(x)<<endl
#define ps(x) cout<<(x)
#define pk(x) cout<<(x)<<" "
#define pfix(d,x) cout << fixed << setprecision(d) << x << endl
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define minel(v) *min_element(all(v))
#define minind(v) distance((v).begin(), min_element(all(v)))
#define maxel(v) *max_element(all(v))
#define maxind(v) distance((v).begin(), max_element(all(v)))
#define p2d(v,n,m) rep(i,n){rep(j,m){pk(v[i][j]);}p("");}
#define fi first
#define se second
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
typedef map<ll, ll> imap;
typedef pair<ll, ll> P;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<pair<ll,ll> > VP;

void pyn(bool ans){
    p(ans?"Yes":"No");
}

//Prime
bool is_prime(ll n){
	if(n==1)return false;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}
vector<ll>divisor(ll n){
	vector<ll>res;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			res.push_back(i);
			if(i!=n/i)res.push_back(n/i);
		}
	}
	return res;
}
map<ll,int>prime_factor(ll n){
	map<ll,int>res;
	for(ll i=2;i*i<=n;i++){
		while(n%i==0){
			res[i]++;
			n/=i;
		}
	}
	if(n!=1)res[n]++;
	return res;
}
vector<ll>prime_enum(int n){
	vector<bool>is_prime(n+1,true);
	is_prime[0]=is_prime[1]=false;
	vector<ll>res;
	for(int i=2;i<=n;i++){
		if(!is_prime[i])continue;
		res.push_back(i);
		for(int j=2*i;j<=n;j+=i){
			is_prime[j]=false;
		}
	}
	return res;
}

//Mod
// mod_tools


#define MFACT_SIZE 1000001

ll fact[MFACT_SIZE]; 

ll mpow(ll x, ll y){
    //d(x)
    if(y==0) return 1;
    if(y%2==0){
        return mpow(x*x%mod,y/2)%mod;
    }
    else{
        return x*mpow(x,y-1)%mod;
    }
}

ll minv(ll x){
    // only available for mod=10^9+7
    return mpow(x,mod-2);
}

void mfact(){
    //prepare fact-array
    fact[0]=1;
    rep(i,1,MFACT_SIZE){
        fact[i]=fact[i-1]*i%mod;
    }
}

ll mcombi(ll n, ll k){
    return (fact[n]*minv(fact[k])%mod)*minv(fact[n-k])%mod;
}


ll llceil(ll a, ll b){
    if(a >= 0){
        return (a+b-1)/b;
    }else{
        return a/b;
    }
}
ll llfloor(ll a, ll b){
    if(a < 0){
        return (a-b+1)/b;
    }else{
        return a/b;
    }
}


struct UnionFind {
  VL data;
  UnionFind(int size) : data(size, -1) { }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool find(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  ll size(int x) {
    return -data[root(x)];
  }
  ll num_root(ll size){
    VL roots;
    rep(i,size)roots.pb(root(i));
    sort(all(roots));
    roots.erase(unique(all(roots)),roots.end());
    return roots.size();
  }
};


struct graph{
    int V;
    vector<VP > v;
    graph(int V) : V(V), v(vector<VP >(V)){}
    void add_diedge(int v1, int v2, ll w){
        v[v1].pb({v2, w});
        v[v2].pb({v1, w});
    }
    void add_edge(int v1, int v2, ll w){
        v[v1].pb({v2, w});
    }
    VL dist = vector<ll>(V, -1);
    VI prever = vector<int>(V,-1);
    VL dijkstra(int start){
        priority_queue<P, vector<P>, greater<P> > que;
        que.push(P(0,start));
        while(!que.empty()){
            P pa = que.top();
            que.pop();
            int u = pa.se;
            if(dist[u] >= 0 && dist[u] < pa.fi)continue;
            dist[u]=pa.fi;
            for(P e : v[u]){
                if(dist[e.fi] < 0 || dist[e.fi] > dist[u] + e.se){
                    dist[e.fi] = dist[u] + e.se;
                    prever[e.fi] = u;
                    que.push(P(dist[e.fi],e.fi));
                }
            }
        }
        return dist;
    }
    void dfs(ll now, ll prv, ll c){
        dist[now]=c;
        for(auto nxt : v[now])if(nxt.fi != prv){
            if(nxt.se % 2)dfs(nxt.fi, now, !c);
            else dfs(nxt.fi, now, c);
        }
    }
    void gprint(){
        rep(i,V){ps(i);ps(": ");for(P x : v[i]){ps(x.fi);ps(",");ps(x.se);ps(" ");}p("");}
    }
 
};

struct SegmentTree {
private:
    int n;
    VL node;

public:
    // 元配列 v をセグメント木で表現する
    SegmentTree(VL v) {
    // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
    // セグメント木全体で必要なノード数は 2n-1 個である
    int sz = v.size();
    n = 1; while(n < sz) n *= 2;
    node.resize(2*n-1, inf);
    for(int i=0; i<sz; i++) node[i+n-1] = v[i];
    for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
    void update(int x, int val) {
    x += (n-1);
    node[x] = val;
    while(x > 0) {
        x = (x - 1) / 2;
        node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }
    // 要求区間 [a, b) 中の要素の最小値を答える
    // // k := 自分がいるノードのインデックス
    // // 対象区間は [l, r) にあたる
    // get a,b+1で呼び出す
    int get(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        d(l)d(r)d(a)d(b)
        if(r <= a || b <= l) return inf;
        // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
        if(a <= l && r <= b) return node[k];
        // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
        // 左側の子を vl ・ 右側の子を vr としている
        // 新しい対象区間は、現在の対象区間を半分に割ったもの
        int vl = get(a, b, 2*k+1, l, (l+r)/2);
        int vr = get(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }    
};

ll a[100001],b[100001],c[100001],d,n,m,x,y,z,h,w,k,mi=inf,ma=-inf,ans,sum,s,t,l,r,res,tmp,itr,p,q;
bool flag;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int dx8[8]={1,1,0,-1,-1,-1,0,1},dy8[8]={0,1,1,1,0,-1,-1,-1};
char cha;
string st;
P pa;
bool fl;

ll f[20];

int main(void){
    cin>>st>>k;
    rep(i,st.size()-1){
        if(st[st.size()-1-i]==st[st.size()-2-i])m++;
        else break;
    }

    rep(i,st.size()-1){
        if(st[i]==st[i+1])n++;
        else break;
    }
    if(n==st.size()-1){p(st.size()*k/2); return 0;}
    rep(i,st.size()-1){
        if(st[i]==st[i+1]){
            sum++;
            st[i+1]='!';
        }
    }
    d(sum);
    ans+=k*sum;
    //末端がiii
    //ii
    d(st[st.size()-1]) 
    if(st[0]==st[st.size()-1])ans-=(k-1)*(n/2+m/2-(n+m)/2);
    p(ans);
    return 0;
}
