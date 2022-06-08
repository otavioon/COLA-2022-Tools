#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  map<ll,int> mp;
  rep(i,n){
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a.rbegin(),a.rend());
  int ans = 0;
  rep(i,n){
    if(!mp.count(a[i])) continue;
    ll b = 1;
    while(b<=a[i]) b*=2;
    ll pe = b - a[i];
    if(mp.count(pe)){
      if(pe==a[i]&&mp[a[i]]==1) continue;
      mp[pe]--;
      mp[a[i]]--;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}