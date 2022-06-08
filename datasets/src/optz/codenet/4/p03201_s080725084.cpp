#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e15;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

ll N, a, ans;

set<ll> S;
vi V;

int main(){
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>a;
    S.insert(a);
  }
  for (int i=0;i<30;++i)V.pb(1<<i);
  while(SZ(S)){
    ll T = *(--S.end());
    S.erase(T);
    ll it = *lb(ALL(V),T);
    ll opp = it - T;
    if (S.lb(opp) != S.ub(opp)){
      S.erase(opp);
      ++ans;
    }
  }
  cout<<ans;
}
