#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
ll gcd(ll x, ll y){
  if(y==0) return x;
  else return gcd(y, x%y);
}
ll lcm(ll x,ll y){
  ll g=gcd(x,y);
  return x/g*y;
}

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>b(n);
  vector<int>c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> c[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  
  ll sum=0;
  rep(i,n){
    ll keyb=b[i];
    ll itc=upper_bound(c.begin(),c.end(),keyb)-c.begin();
    ll ita=lower_bound(a.begin(),a.end(),keyb)-a.begin();
    itc=n-itc;
    sum+=ita*itc;
  }
  cout<<sum<<endl;
}
