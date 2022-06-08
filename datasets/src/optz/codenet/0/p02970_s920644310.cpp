#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(a,b) for(int a=0;a<(b);++a)
#define REP1(i,n) for(int i=1;i<=(n);++i)
#define debug(x) cerr<<#x<<": "<<x<<'\n'
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define INF (1<<29)
#define PI 3.14159265358979
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

template<class T=int>
T in(){T x;cin>>x;return (x);}
template<class T>
void print(T& x){cout<<x<<'\n';}

const int MOD =(int)1e9+7;
const int MAX =510000;
ll fac[MAX],finv[MAX],inv[MAX];
void COMint(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
ll gcd(ll a,ll b){
    if(b==0)return a;
    if(a>b){
        swap(a,b);
    }
    return gcd(a,b%a);
}
ll lcm(ll a,ll b){
    ll g;g=gcd(a,b);
    return a*b/g;
}
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}

vector<pair<int,ll>> vec[100000];
ll cost[100000];
void dfs(int now,ll COST){
    cost[now]=COST;
    int next;
    REP(i,vec[now].size()){
        next=vec[now][i].first;
        if(cost[next]<0){
            dfs(next,COST+vec[now][i].second);
        }
    }
}
int counter(int x){
    if(!x)return 0;
    return counter(x>>1)+(x&1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N=in();
    int D=in();
    int ans;
    ans=N/(2*D);
    if(N%(2*D)!=0)ans++;
    cout<<ans<<endl;
    return 0;
}
