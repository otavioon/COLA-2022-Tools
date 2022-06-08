// g++ macro.cpp -std=c++14
#include <bits/stdc++.h> //STL include
typedef long long ll;// long long int
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;//namespace

#define dump(x)  cout << #x << " = " << (x) << endl;// debug cout
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl;
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl;

#define SANKOU(n,a,b) cout << ((n) ? (a) : (b) ) << endl;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)// for macro
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

#define WFA(d,v) REP(k,v)REP(i,v)REP(j,v)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);// warshall-floyd

#define CIN(x) int x;cin>>x;
#define SCIN(x) string x;cin>>x;
#define COUT(x) cout<<(x)<<endl;
#define SCOUT(x) cout<<(x)<<" ";
#define ENDL cout<<endl;

#define VECCIN(x) for(auto&youso_: (x) )cin>>youso_;
#define VECCOUT(x) for(auto&youso_: (x) )cout<<youso_<<" ";cout<<endl;

#define ALL(obj) (obj).begin(),(obj).end()// iterator

#define UNIQUE(obj) sort(ALL( obj )); obj.erase(unique(ALL(obj)),obj.end());

#define P pair<int,int>
#define V vector<int>
#define M map<int,int>

#define pb(a) push_back(a)//push_back
#define mp make_pair// make_pair


int main(){


    ll n;cin>>n;
    pair<ll,ll> p;
    for(ll i=1;i<sqrt(n)+1;++i)if(n%i==0){p.first=i;p.second=n/i;}
    int fdig=log10(p.first)+1;
    int sdig=log10(p.second)+1;

    COUT(max(fdig,sdig));
    return 0;
}
