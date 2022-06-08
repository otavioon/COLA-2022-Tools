#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<ll,int> p;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) a[i] -= i + 1;
  int b = a[n / 2];
  ll ans = 0;
  sort(a.begin(), a.end());
  rep(i, n) ans += abs(a[i] - b);
  cout << ans << endl;
}
