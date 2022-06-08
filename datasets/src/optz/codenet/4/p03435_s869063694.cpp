#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16

ll n=3;
ll c[3][3];

int main(){
	rep(i,n)rep(j,n)cin>>c[i][j];
  rep(i,n){
    set<ll> st;
    rep(j,n){
      st.insert(c[i][j]-c[(i+1)%n][j]);
    }
    if(st.size()>1){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
	return 0;
}
