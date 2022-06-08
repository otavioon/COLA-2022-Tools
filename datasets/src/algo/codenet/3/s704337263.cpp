#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int n;
  cin >> n;
  vi a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  ll ans = 0;
  rep(i, n){
    int num = b[i];
    ll cntTop = 0;
    ll cntBottom = 0;
    rep(j, n){
      if(a[j] < num) cntTop++;
    }
    rep(j, n){
      if(c[j] > num) cntBottom++;
    }
    ans += cntTop * cntBottom;
  }
  cout << ans << endl;
}